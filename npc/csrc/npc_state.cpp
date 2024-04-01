#include "include/common.h"



NPCState npc_state = { .state = NPC_STOP };

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0);
  return !good;
}

// 检测到ebreak指令，程序运行结束，退出仿真
extern "C" void npc_trap() {
    printf("Execute the ebreak Instruction\n");
    npc_state.state = NPC_END;
    npc_state.halt_ret = NPC_REG[10];
    // printf("regs[10] = 0x%.8x\n", NPC_REG[10]);
    if (npc_state.halt_ret == 0)
    {
      printf("HIT GOOD TRAP!\n");
    }
    else
    {
      printf("HIT BAD TRAP!\n");
    }
}

// 打印寄存器值
extern "C" void reg_print() {
  for (size_t i = 0; i < sizeof(NPC_REG)/sizeof(NPC_REG[0]); i++)
  {
    printf("regs[%ld] = 0x%.8x\n", i, NPC_REG[i]);
  }
  
}

// 接收寄存器rf[10]的值
// extern "C" void display_regs(word_t* regi) {
//   npc_state.halt_ret = *regi;
//   printf("npc_state.halt_ret = %.8x\n", npc_state.halt_ret);
// }