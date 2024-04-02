/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();
void wp_difftest();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
  /* 可配置观察点检测功能是否开启 */
  IFDEF(CONFIG_WATCHPOINT, wp_difftest());
}

/* exec_once()函数覆盖了指令周期的所有阶段: 取指, 译码, 执行, 更新PC,
 * 调用isa_exec_once取指并执行，指令与架构相关，从isa_exec_once()返回后s->snpc正好为下一条指令的PC
 * 将cpu.pc置为下一条应该执行的指令的地址，这个地址在s->dnpc中
 * snpc: static next PC 指的是在内存中下一个地址位置上的指令
 * dnpc: dynamic next PC 指的是程序运行时执行的下一条指令，由于存在指令的跳转，下一个执行的指令未必是内存中的下一个指令
 * 根据是否开启了itrace，将第一步执行的指令记录到s->logbuf中，然后会在trace_and_difftest中输出
*/
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

/* 调用exec_once执行每条指令
 * 调用trace_and_difftest记录trace、执行difftest和检查watchpoint
 * 检查是否程序应该退出（运行到了最后一条指令或者别的原因退出）
 * 更新设备状态
*/
static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    /* difftest如果检测出变化，返回的state肯定不是NEMU_RUNNING,所以跳出循环，中断cpu执行*/
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

/* statistic()这个函数用于记录关于模拟器性能和运行状态的信息，例如主机运行时间、总指令数和模拟频率。
 * 这些信息对于性能分析和调试非常有用。
 */
static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
/* 首先，根据传入的参数n和预定义的MAX_INST_TO_PRINT比较，确定是否打印每条指令的执行信息。
 * 接着，根据当前的nemu_state.state状态进行判断：
 * 如果状态为NEMU_END或NEMU_ABORT，输出程序执行已结束的提示信息，并返回函数。
 * 否则，将nemu_state.state设置为NEMU_RUNNING表示程序正在运行。
 * 获取当前时间作为计时器的起始时间。
 * 调用execute(n)函数，执行指定数量的指令。
 * 执行完指定数量的指令后，获取当前时间作为计时器的结束时间，并计算指令执行的时间。
 * 根据nemu_state.state的值进行判断：
 * 如果状态为NEMU_RUNNING，将nemu_state.state设置为NEMU_STOP，表示程序执行已暂停。
 * 如果状态为NEMU_END或NEMU_ABORT，根据具体的状态输出相应的日志信息，提示程序是否执行成功。
 * 如果状态为NEMU_QUIT，执行统计操作。
 * 总体来说，该函数的功能是模拟CPU的工作。它根据给定的指令数量执行相应数量的指令，并根据当前的状态进行相应的处理, 
 * 包括输出提示信息,设置状态,记录执行时间及执行统计操作. 
 * */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  /* 对execute()执行后返回的state做判断，若为RUNNING和STOP则跳回sdb_mainloop()循环*/
  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // 打印错误指令发生时执行的最近的16(可配置)条指令
      display_trace();  
      // fall through
    case NEMU_QUIT: statistic();
  }
}
