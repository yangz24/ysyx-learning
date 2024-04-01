#include "include/common.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

VCPU* top;

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new VCPU; 
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("./build/obj_dir/waveform.vcd");
}

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	// tfp->dump(contextp->time());
}


void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}

static void single_cycle() {
  top->clk = 0; step_and_dump_wave();
  top->clk = 1; step_and_dump_wave(); 
}

static void reset(int n) {
  top->rst = 1;
  while (n -- > 0) single_cycle();
  top->rst = 0;
}

void init_monitor(int argc, char *argv[]);
int is_exit_status_bad();


int main(int argc, char *argv[]) {

  for (size_t i = 0; i < argc; i++)
  {
    printf("argv = %s, argc = %ld\n", argv[i], i);
  }
  sim_init();
  reset(10);

  init_monitor(argc, argv);

  while(npc_state.state != NPC_END || npc_state.halt_ret != 0)
  {
    top->Instr = vaddr_read(top->PC, 4);
    printf("取到指令了, pc = " FMT_PADDR  "  Instr =" FMT_WORD "\n", top->PC, top->Instr);
    single_cycle();    
    // reg_print();
  } 

  sim_exit();
  top->final();
  delete top;

  return is_exit_status_bad();
}
