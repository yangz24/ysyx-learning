/******************************************************************
 * paddr.c 用于开辟一块物理内存区域, 
 * 同时定义了物理地址与宿主机(npc)虚拟地址之间的转化函数
 * 读写物理地址时会判断输入的地址是否落在开辟的内存区域内,若不在则越界报错
*******************************************************************/

#include "include/paddr.h"
#include "include/host.h"
#include "include/sim.h"


extern VCPU* CPU;

static uint8_t pmem[CONFIG_MSIZE] = {};

/* 将客户程序地址转化为npc这个宿主地址空间,其实就是物理地址转化为虚拟地址 */
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
/* 将npc这个宿主的地址转化为客户程序的地址空间,其实就是虚拟地址转化为物理地址 */
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

/* 中间函数,传入客户程序物理地址, 由guest_to_host函数转化为npc虚拟地址后,
 * 由定义在host.h中的host_read函数读回虚拟内存空间的数据
*/
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

/* 中间函数,传入客户程序物理地址, 由guest_to_host函数转化为npc虚拟地址后,
 * 由定义在host.h中的host_write函数将数据写入虚拟内存空间
*/
static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

/* 终端打印访问物理地址溢出的信息 */
static void out_of_bound(paddr_t addr) {
  printf("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD "\n",
      addr, PMEM_LEFT, PMEM_RIGHT, PC);
}

/* 初始化存储空间(暂且不实现)并打印内存空间首尾位置 */
void init_mem() {
  printf("physical memory area [" FMT_PADDR ", " FMT_PADDR "]\n", PMEM_LEFT, PMEM_RIGHT);
}

/* 读客户程序物理地址的函数 */
word_t paddr_read(paddr_t addr, int len) {
  if (in_pmem(addr)) {
    // IFDEF(CONFIG_MTRACE, display_pread(addr, len));
    return pmem_read(addr, len);
  }
  out_of_bound(addr);
  // assert(0);
  return 0;
}

/* 写数据至客户程序物理地址的函数 */
void paddr_write(paddr_t addr, int len, word_t data) {
  if (in_pmem(addr)) { 
    // IFDEF(CONFIG_MTRACE, display_pwrite(addr, len, data));
    pmem_write(addr, len, data); 
    return; 
  }
  out_of_bound(addr);
}

/* verilog代码中内存控制模块调用的函数 MemCtrl.v */
extern "C" int mem_read(paddr_t Addr, int isInstr) {
  word_t data_out = paddr_read(Addr, 4);
  if (isInstr)
  {
    // printf("InstrAddr = 0x%08x, Instr = 0x%08x\n", Addr, data_out);
    return data_out;
  }
  // printf("MemAddr = 0x%08x\n", Addr);
  return data_out;
}

extern "C" void mem_write(paddr_t Addr, paddr_t DataIn, char Wmask) { 
  for (size_t i = 0; i < 4; i++)
  {
    if (Wmask >> i & 0x1)
    {
      paddr_write(Addr+i, 1, DataIn >> i*8);
    }
  }
}
