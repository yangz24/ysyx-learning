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

/******************************************************************
 * paddr.c 用于开辟一块物理内存区域并初始化, 
 * 同时定义了物理地址与宿主机(npc)虚拟地址之间的转化函数
 * 读写物理地址时会判断输入的地址是否落在开辟的内存区域内,若不在则越界报错
*******************************************************************/

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

/* 将客户程序地址转化为nemu这个宿主地址空间,其实就是物理地址转化为虚拟地址 */
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
/* 将nemu这个宿主的地址转化为客户程序的地址空间,其实就是虚拟地址转化为物理地址 */
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

/* 中间函数,传入客户程序物理地址, 由guest_to_host函数转化为nemu虚拟地址后,
 * 由定义在host.h中的host_read函数读回虚拟内存空间的数据
*/
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

/* 中间函数,传入客户程序物理地址, 由guest_to_host函数转化为nemu虚拟地址后,
 * 由定义在host.h中的host_write函数将数据写入虚拟内存空间
*/
static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}
/* 终端打印访问物理地址溢出的信息 */
static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

/* 初始化存储空间 */
void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
#ifdef CONFIG_MEM_RANDOM
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }
#endif
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

/* 读客户程序物理地址的函数
 * likely是一个宏，用于告诉编译器扣个条件表达式的结果可能为真或为假，
 * 有助于编译器在生成代码时进行优化，使得执行频率更高的路径更快。
 * likely：表示条件表达式很可能为真（true），即编译器会认为这个分支是比较常见的情况。
 * unlikely：表示条件表达式很可能为假（false），即编译器会认为这个分支是不太常见的情况。
*/
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) {
    IFDEF(CONFIG_MTRACE, display_pread(addr, len));
    return pmem_read(addr, len);
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

/* 写数据至客户程序物理地址的函数 */
void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { 
    IFDEF(CONFIG_MTRACE, display_pwrite(addr, len, data));
    pmem_write(addr, len, data); 
    return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
