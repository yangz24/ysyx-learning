#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VALU.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VALU* top;

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new VALU;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("./obj_dir/waveform.vcd");
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}

// 定义32位ALU的加法函数
unsigned int alu_add(unsigned int operand1, unsigned int operand2) {
    return operand1 + operand2;
}
// 定义32位ALU的减法函数
unsigned int alu_sub(unsigned int operand1, unsigned int operand2) {
    return operand1 - operand2;
}
// 定义32位ALU的逻辑与函数
unsigned int alu_and(unsigned int operand1, unsigned int operand2) {
    return operand1 & operand2;
}
// 定义32位ALU的逻辑或函数
unsigned int alu_or(unsigned int operand1, unsigned int operand2) {
    return operand1 | operand2;
}
// 定义32位ALU的逻辑异或函数
unsigned int alu_xor(unsigned int operand1, unsigned int operand2) {
    return operand1 ^ operand2;
}
// 定义32位ALU的左移函数
unsigned int alu_shiftleft(unsigned int operand1, unsigned int operand2) {
	return operand1 << (operand2 & 0x1F);	
}
// 定义32位ALU的逻辑右移函数
unsigned int alu_shiftrightl(unsigned int operand1, unsigned int operand2) {
	return operand1 >> (operand2 & 0x1F);	
}
// 定义32位ALU的算数右移函数
int alu_shiftrighta( int operand1,  int operand2) {
	return operand1 >> (operand2 & 0x1F);	
}

int main(int argc, char** argv) {
	sim_init();
	top->A = 0xABCD1234;
	top->B = 0x1234ABCD;
	int result;

// 选择加法器输出，做加法
	top->ALUctr = 0b0000;
	result = alu_add(top->A, top->B);
	step_and_dump_wave();
	printf("A + B, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择加法器输出，做减法
	top->ALUctr = 0b1000;
	result = alu_sub(top->A, top->B);
	step_and_dump_wave();
	printf("A - B, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择逻辑与输出
	top->ALUctr = 0b111;
	result = alu_and(top->A, top->B);
	step_and_dump_wave();
	printf("A & B, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择逻辑或输出
	top->ALUctr = 0b110;
	result = alu_or(top->A, top->B);
	step_and_dump_wave();
	printf("A | B, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择逻辑异或输出
	top->ALUctr = 0b100;
	result = alu_xor(top->A, top->B);
	step_and_dump_wave();
	printf("A ^ B, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择移位器输出，左移
	top->ALUctr = 0b001;
	result = alu_shiftleft(top->A, top->B);
	step_and_dump_wave();
	printf("Shiftleft, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择移位器输出，逻辑右移
	top->ALUctr = 0b0101;
	result = alu_shiftrightl(top->A, top->B);
	step_and_dump_wave();
	printf("Shiftrightl, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
// 选择移位器输出，算数右移
	top->ALUctr = 0b1101;
	result = alu_shiftrighta(top->A, top->B);
	step_and_dump_wave();
	printf("Shiftrighta, Expect result = 0x%x, get 0x%x\n", result, top->ALUout);
	
/*	int i,j;
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
*/
	sim_exit();
	top->final();
	delete top;
	return 0;
}
