#include "include/sim.h"
#include "include/utils.h"


extern VCPU* CPU;

NPCState npc_state = { .state = NPC_STOP };

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
  return !good;
}

// 检测到ebreak指令，程序运行结束，退出仿真
extern "C" void npc_trap() {
    printf("Execute the ebreak Instruction\n");
    npc_state.state = NPC_END;
    npc_state.halt_ret = NPC_REG[10];
    npc_state.halt_pc = PC;
    return;
}

// 打印寄存器值
void reg_display() {
  for (size_t i = 0; i < sizeof(NPC_REG)/sizeof(NPC_REG[0]); i++)
  {
    printf("regs[%ld] = 0x%.8x\n", i, NPC_REG[i]);
  }
  
}
