/***************************************************************************************
* npc作为difftest的dut
***************************************************************************************/

#include <dlfcn.h>
#include "include/utils.h"
#include "include/paddr.h"
#include "include/sim.h"
#include "include/isa.h"



#ifdef CONFIG_DIFFTEST

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

extern CPU_state cpu;


/* 回调函数 */
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;

/* 检查REF和DUT的寄存器核心函数 */
bool difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int reg_num = ARRLEN(NPC_REG);
  for (size_t i = 0; i < reg_num; i++)
  {
    if (ref_r->gpr[i] != NPC_REG[i])
    {
      printf("reg[%ld] is different after executing instruction at pc = " FMT_WORD
          ", right = " FMT_WORD ", wrong = " FMT_WORD "\n",
           i, PC, ref_r->gpr[i], NPC_REG[i]);
      return false;
    }
  }
  if (ref_r->pc != pc)
  {
    printf("next pc is different after executing instruction at pc = " FMT_WORD
    ", right = " FMT_WORD ", wrong = " FMT_WORD "\n", PC, ref_r->pc, pc);
    return false;
  }
  return true;
}

static bool is_skip_ref = false;
int hold_cycle = 2;

// this is used to let ref skip instructions which
// can not produce consistent behavior with npc
void difftest_skip_ref() {
  is_skip_ref = true;
}

/* 初始化difftest */
void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  printf("Differential testing: %s\n", ANSI_FMT("ON", ANSI_FG_GREEN));
  printf("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.\n", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  cpu.pc = RESET_VECTOR;
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = PC;
    // reg_display();
  }
}

void difftest_step(vaddr_t pc) {
  CPU_state ref_r;

  /* 如果调用了difftest_skip_ref()函数, 会将is_skip_ref置1, 从而跳过此次difftest, 只将dut的寄存器状态拷贝到ref中 */
  if (is_skip_ref) {
    hold_cycle--;
    // to skip the checking of an instruction, just copy the reg state to reference design
    if (hold_cycle == 0)
    {
      ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
      is_skip_ref = false;
      // printf("difftest skipped at PC = " FMT_PADDR "\n", PC);
      // printf("nextpc= " FMT_PADDR "\n", cpu.pc);
      hold_cycle = 2;
      return;
    }
  }
    // printf("difftest at PC = " FMT_PADDR "\n", PC);
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
  // printf("PC = 0x%08x\n", pc);
}

#endif
