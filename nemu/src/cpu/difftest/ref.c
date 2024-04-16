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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include "../../isa/riscv32/local-include/reg.h"

typedef struct diff_context_t {
  word_t gpr[32];
  word_t pc;
}diff_context;

// extern CPU_state getcpu;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF)
  {
    for(size_t i=0; i<n; i++) {
    	uint8_t mem_data = *((uint8_t *)buf + i);
    	paddr_write(addr + i, 1, mem_data);
      // printf("addr+i= %lx, mem_data= %x\n", addr+i, mem_data);
    }
  } else {
    assert(0);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  diff_context *dut_state = (diff_context*)dut;
    if (direction == DIFFTEST_TO_REF)
  {
    for (size_t i = 0; i < REG_NUM; i++)
    {
      gpr(i) = dut_state->gpr[i];
      // printf("初始化gpr(%ld) = %x\n", i, gpr(i));
    }
    cpu.pc = dut_state->pc;
    // printf("初始化cpu.pc = %x\n", cpu.pc);
  } else {
    for (size_t i = 0; i < REG_NUM; i++)
    {
      dut_state->gpr[i] = cpu.gpr[i];
      // printf("复制ref的gpr(%ld) = %x\n", i, gpr(i));
    }
    dut_state->pc = cpu.pc;
    // printf("ref下一条cpu.pc = %x\n", cpu.pc);
  }
  
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
