#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VCPU.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VCPU* top;
/* 定义一个img数组用于初始化指令存储器*/
static const uint img[] = {
  0b00000000011100000000000010010011, // addi x1 x0 7
  0b00000000000100001000000010010011, // addi x1 x0 1
  0b00000000001100001000000100010011, // addi x2 x1 3
  0b00000000011100001000000100010011, // addi x2 x1 7
  0b00000000000000000000000001110011  // ebreak
};



/* 申请一块内存并初始化 */
uint* init_mem(size_t size){
  uint* memory = (uint*)malloc(size * sizeof(uint));
  memcpy(memory, img, sizeof(img));
  if (memory == NULL) {
      printf("Memory allocation failed.\n");
      exit(0);  
  }
  return memory;
}
/* 物理内存到npc内存的转化 */
uint guest_to_host(uint paddr) { return paddr - 0x80000000; }
/* 读内存里的指令 */
uint mem_read(uint* memory, uint paddr ){
  uint vaddr = guest_to_host(paddr);
  return memory[vaddr >> 2];
}

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new VCPU; 
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("./obj_dir/waveform.vcd");
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

// 检测到ebreak指令，程序运行结束，退出仿真
extern "C" int npc_trap() {
    printf("trap!\n");
    tfp->close();
    exit(0);
}

int main() {
  uint* memory = init_mem(5);
  int ret = 1;
  sim_init();
  reset(10);

  while(1)
  {
    top->Instr = mem_read(memory, top->InstrMemRdAddr);
    single_cycle();
  }

  free(memory); 
  sim_exit();
  top->final();
  delete top;
  return 0;
}
