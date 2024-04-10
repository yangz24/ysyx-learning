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
 * paddr.c 用于在nemu数据空间开辟一块内存区域并初始化, 供其上运行的CPU访问,
 * CPU即是nemu上运行的客户机程序.
 * CPU读写该空间地址时会判断输入的地址是否落在开辟的内存区域内,若不在则越界报错.
 * 定义了该空间与宿主机(操作系统)地址之间的转化函数.
 * nemu的内存映射关系我画了一张图--nemu内存映射.drawio.png
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

/* pmem与nemu数据空间(其实就是宿主机的一段内存空间)之间的映射关系 */
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

/* 若访问地址落在物理内存空间pmem, 由guest_to_host函数转化为host地址后,
 * 由定义在host.h中的host_read函数读回内存空间的数据
*/
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

/* 若访问地址落在物理内存空间pmem, 由guest_to_host函数转化为host地址后,
 * 由定义在host.h中的host_write函数将数据写入内存空间
*/
static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}
/* 终端打印CPU访问其物理地址溢出的信息 */
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

/* 访问客户程序地址的函数
 * 若访问地址落在客户程序物理地址pmem上,则使用访问物理地址
 * 若访问地址落在设备映射地址上,则访问设备映射的目标空间
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

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { 
    IFDEF(CONFIG_MTRACE, display_pwrite(addr, len, data));
    pmem_write(addr, len, data); 
    return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
