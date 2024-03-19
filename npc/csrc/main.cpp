#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
<<<<<<< HEAD
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vtop* top;

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vtop;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("dump.vcd");
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}

int main(int argc, char** argv) {
	sim_init();
	int i,j;
	top->x0 = 0b00;
	top->x1 = 0b00;
	top->x2 = 0b00;
	top->x3 = 0b00;
	top->Y = 0b00;
	for(i=0;i<4;i++){
		for(j=0;j<16;j++){
			top->x0 = !top->x0;
			if(j%2==1) top->x1 = !top->x1;
			if(j%4==3) top->x2 = !top->x2;
			if(j%8==7) top->x3 = !top->x3;
			step_and_dump_wave();
			printf("Y=%x, x3x2x1x0=%x%x%x%x, F=%x\n", top->Y, top->x3, top->x2, top->x1, top->x0, top->F);
		}
	top->Y += 0b01;
	}
	sim_exit();
	top->final();
	delete top;
	return 0;
}
=======
#include "Vtop.h"
#include "verilated.h"


 int main(int argc, char** argv) {
      VerilatedContext* contextp = new VerilatedContext;
      contextp->commandArgs(argc, argv);
      Vtop* top = new Vtop{contextp};
      while (!contextp->gotFinish()) {
            int a = rand() & 1;
            int b = rand() & 1;
            top->a = a;
            top->b = b;
            top->eval();
            printf("a = %d, b = %d, f = %d\n", a, b, top->f);
            assert(top->f == (a ^ b));
      }
      delete top;
      delete contextp;
      return 0;
  }
>>>>>>> pa0
