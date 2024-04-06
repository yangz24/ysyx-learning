/***************************************************************************************
* 这里定义了一些有用的宏
***************************************************************************************/

#ifndef __UTILS_H__
#define __UTILS_H__

#include "common.h"

// ----------- state -----------
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

/* state npc当前状态
 * halt_pc 暂停时候的pc
 * halt_ret 暂停结束复位时候的pc
*/
typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NPCState;

extern NPCState npc_state;

extern void reg_print();


// ----------- log -----------
/* 控制终端文本颜色和格式的 ANSI 转义序列的定义。
 * 这些转义序列可以在支持 ANSI 转义序列的终端中用于改变文本的颜色和格式。
 */
#define ANSI_FG_BLACK   "\33[1;30m"   // 设置前景为黑色
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"   // 品红色
#define ANSI_FG_CYAN    "\33[1;36m"   // 青色
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"   // 设置背景为黑色
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;35m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"      // 重置终端前景色、背景色为默认值

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

/* log_write是一个写入日志的宏，使用了可变参数__VA_ARGS__ */
#define log_write(...)  \
  do { \
    extern FILE* log_fp; \
    extern bool log_enable(); \
    if (log_enable()) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0) \

#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)


// ------------ trace -------------------------
// in diaasm.cc
extern "C" void init_disasm(const char *triple);
// in itrace.c
void trace_inst(word_t pc, uint32_t inst);
void display_trace();
// in mtrace.c
void display_pread(paddr_t addr, int len);
void display_pwrite(paddr_t addr, int len, word_t data);

#endif

