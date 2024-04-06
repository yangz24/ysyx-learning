#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include "common.h"

/* 定义了客户物理内存区域地址的首尾指针 */
#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

/* 定义了PC的复位值 */
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)


/* 将客户程序中的客户物理地址转化为npc中的主机虚拟地址 */
uint8_t* guest_to_host(paddr_t paddr);

/* 将npc中的主机虚拟地址转化为客户程序中的客户物理地址 */
paddr_t host_to_guest(uint8_t *haddr);

/* 检查物理地址是否溢出 */
static inline bool in_pmem(paddr_t addr) {
  // printf("address = 0x%08x\n", addr);
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

/* 从物理地址读出数据 */
word_t paddr_read(paddr_t addr, int len);

/* 将数据写入物理地址对应空间 
 * mem的物理地址空间范围为：[0x80000000, 0x87ffffff]
*/
void paddr_write(paddr_t addr, int len, word_t data);

/* verilog代码中内存控制模块调用的函数 MemCtrl.v */
extern "C" int mem_read(paddr_t Addr, int isInstr);

extern "C" void mem_write(paddr_t Addr, paddr_t DataIn, char Wmask);

#endif
