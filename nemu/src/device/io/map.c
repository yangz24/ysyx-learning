/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

void trace_device_read(paddr_t addr, int len, IOMap *map);
void trace_device_write(paddr_t addr, int len, IOMap *map);

#define IO_SPACE_MAX (2 * 1024 * 1024) // 2MB

/* 定义两个静态全局变量 io_space 和 p_space，分别用来保存 I/O 空间的起始地址和当前可用空间的地址。这两个指针都被初始化为 NULL。*/
static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

/* new_space接受一个大小参数size, 用于在io_space分配的内存中分配一个新的子区块, 并返回子区块的起始地址.
 * 
*/
uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  //页对齐操作
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  // 确保分配后的 p_space 地址不超过 io_space 加上 IO_SPACE_MAX 的限制，保证不会越界。
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

/* 检查访问IO映射是否越界 */
static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

/* 调用设备提供的回调函数 */
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

/* 初始化映射空间, io_space表示映射空间的起始地址, p_space表示当前空间的位置
 * 预先分配大内存块（由 malloc 分配）
 * 实现了一个简单的内存池，其中通过 new_space 函数可以动态地分配固定大小并且页对齐的内存子区块。
 * 这种方法可以提高内存的使用效率，尤其是在需要频繁分配和释放小块内存的场景中。
 */
void init_map() {
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

/**
 * @brief 用于读取设备数据
 * 访问时, 会触发相应的回调函数, 对设备和目标空间的状态进行更新. 
 * @param addr 访问内存的地址(其实是访问设备映射到内存空间的地址)
 * @param len 访问字节长度
 * @param map 设备映射结构体
 * @return ret 从设备读取到的值
*/
word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr); 
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read(map->space + offset, len);
  // 如果开启了dtrace, 则打印设备读写信息
  IFDEF(CONFIG_DTRACE, trace_device_read(addr, len, map));
  return ret;
}

/**
 * @brief 用于将数据写入设备目标空间
 * 访问时, 会触发相应的回调函数, 对设备和目标空间的状态进行更新. 
 * @param addr 访问内存的地址(其实是访问设备映射到内存空间的地址)
 * @param len 写入字节长度
 * @param data 写入数据
 * @param map 设备映射结构体
*/
void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write(map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
    // 如果开启了dtrace, 则打印设备读写信息
  IFDEF(CONFIG_DTRACE, trace_device_write(addr, len, map));
}
