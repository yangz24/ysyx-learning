#include "include/sim.h"

VerilatedContext* contextp;
VerilatedVcdC* tfp;
VCPU* CPU;

/* 函数声明 */
void sim_init();
void step_and_dump_wave();
void sim_exit();
void single_cycle();
void reset(int n);

/* 仿真初始化 */
void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	CPU = new VCPU; 
	contextp->traceEverOn(true);
	CPU->trace(tfp,0);
	tfp->open("./build/obj_dir/waveform.vcd");
}
/* 波形抓取 */
void step_and_dump_wave(){
	CPU->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}
/* 仿真退出 */
void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}
/* 模拟时钟变化 */
void single_cycle() {
  CPU->clk = 0; step_and_dump_wave();
  CPU->clk = 1; step_and_dump_wave(); 
}
/* 复位 */
void reset(int n) {
  CPU->rst = 1;
  while (n -- > 0) single_cycle();
  CPU->rst = 0;
}