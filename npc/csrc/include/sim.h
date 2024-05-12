/******************************************************
 * 仿真相关函数的函数声明,需要调用这些函数可以包含此头文件
*******************************************************/

#ifndef __SIM_H__
#define __SIM_H__

#include "common.h"

// verilator 库
#include "verilated.h"
#include "verilated_fst_c.h"
#include "VCPU.h"
#include "VCPU___024root.h"

extern VerilatedContext* contextp;
extern VerilatedFstC* tfp;
extern VCPU* CPU;


#ifdef CONFIG_DIFFTEST
#define NEXTPC CPU->nextPC
#define Instr CPU->diff_Instr
#define DIFFEN CPU->diff_enable
#endif

#define PC CPU->diff_PC
#define NPC_REG CPU->rootp->CPU__DOT__u_IDU__DOT__u_RegisterFile__DOT__rf
#define EBREAK CPU->nextPC



/* 仿真初始化 */
void sim_init();
/* 波形抓取 */
void step_and_dump_wave();
/* 仿真退出 */
void sim_exit();
/* 模拟时钟变化 */
void single_cycle();
/* 复位 */
void reset(int n);

#endif
