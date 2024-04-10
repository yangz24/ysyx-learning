#include "include/vaddr.h"
#include "include/sim.h"
#include "include/utils.h"
#include "include/isa.h"
#include "include/config.h"

CPU_state cpu;

#define MAX_INST_TO_PRINT 10
static bool g_print_step = false;

#ifdef CONFIG_DIFFTEST
void difftest_step(vaddr_t pc);
#endif

static void exec_once() {
    single_cycle();
    // CPU->Instr = vaddr_read(CPU->PC, 4);
    /* itrace */
    #ifdef CONFIG_ITRACE
    trace_inst(PC, Instr);
    if (g_print_step)
    {
      printf("取到指令: pc = " FMT_PADDR  "  Instr = " FMT_WORD "\n", PC, Instr);
    }
    #endif
    
    cpu.pc = PC;
    for (size_t i = 0; i < 32; i++)
    {
      cpu.gpr[i] = NPC_REG[i];
      // printf("执行后的cpu.gpr[%ld]=%x\n", i, cpu.gpr[i]);
    }
    // printf("下一条cpu.pc = %x\n", cpu.pc);
}

static void execute(uint64_t n) {
  for (;n > 0; n --) {
    exec_once();
    #ifdef CONFIG_DIFFTEST
    difftest_step(PC);
    #endif
    if (npc_state.state != NPC_RUNNING) break;
  }
}

void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  execute(n);

  /* 对execute()执行后返回的state做判断，若为RUNNING则改为STOP,跳回sdb_mainloop()循环*/
  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      printf("npc: %s at pc = " FMT_WORD "\n",
          (npc_state.state == NPC_ABORT ? "ABORT " :
           (npc_state.halt_ret == 0 ? "HIT GOOD TRAP " :"HIT BAD TRAP ")),
          npc_state.halt_pc);
      // 打印错误指令发生时或执行到ebreak指令时,执行的最近的16(可配置)条指令:
      #ifdef CONFIG_ITRACE
      display_trace(); 
      #endif 
      // fall through
    case NPC_QUIT: ;
  }
}