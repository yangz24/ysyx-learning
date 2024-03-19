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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void isa_watchpoint_display();
word_t vaddr_read(vaddr_t addr, int len);
void wp_watch(char *expr, word_t res);
void wp_remove(int no);


/* We use the `readline' library to provide more flexibility to read from stdin. */
/* 定义了一个名为 rl_gets 的函数，主要功能是从用户输入中读取一行文本，并将其返回作为字符串。
 * 同时，它会将用户输入的文本添加到历史记录中，以便用户可以通过按上下箭头键来检索先前输入的命令。
 */
static char* rl_gets() {
  static char *line_read = NULL;
  /* 检查line_read是否为空（即是否指向某个内存地址），若是，释放line_read所指向的内存，将line_read置为NULL*/
  if (line_read) {
    free(line_read);
    line_read = NULL;
  }
  /* readline函数从标准输入读取用户输入的内容，并将结果赋给line_read*/
  line_read = readline("(nemu) ");
  /* 若line_read不为空且指向的字符串非空，则调用add_history(line_read)将用户输入的内容添加到历史记录中。*/
  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int n = 0;   //存储执行的指令步数

/* 检查是否没有给定参数，如果是，则执行一行代码。 
 * 如果给定了参数，则提取参数值。
 */
  if (arg == NULL) {
    n = 1;
  } else {
    n = strtol(arg, NULL, 10);
  }

  /* 给的参数不能大于10*/
  if (n > 10)
  {
    printf(ANSI_FMT("Usage: si N (n <= 10).", ANSI_FG_RED));
    return 0;
  }
   cpu_exec(n);

/* ch - '0'：这部分代码实际上是将字符 ch 转换为对应的数字。
 * 在ASCII编码中，数字字符 '0' 到 '9' 是依次排列的，因此用当前字符减去 '0' 的ASCII码值，可以得到对应的数字值。
 * 例如，假设 ch 是字符 '5'，那么表达式 ch - '0' 的结果就是整数 5。
 * n = n * 10 + (ch - '0')：这个表达式则是将之前解析得到的数字乘以 10（相当于进位），然后加上当前解析得到的数字。
 * 这种操作通常用于将一系列字符形式的数字转换为对应的整数。
 * char ch;
 * while (*arg != '\0') {
 *  ch = *arg++;
 *  n =  n * 10 + (ch - '0');
 * }
 * if (n == 0) n = 1;
 * cpu_exec(n);
 */
  return 0;
}

static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

/* 检查是否没有给定参数，如果是，则打印需要参数的提示信息。
 * 如果给定了参数，且参数为r，则打印寄存器状态，若参数为w, 则打印观测点信息。
 */
  if (arg == NULL) {
     printf("Usage: info r (registers) or info w (watchpoints)\n");
     return 0;    
  } 
  else if (strcmp(arg, "r") == 0) {
     isa_reg_display();
  }
  else if (strcmp(arg, "w") == 0)
  {
     isa_watchpoint_display();
  }
  else {
     printf("Unknown command '%s'\nUsage: info r (registers) or info w (watchpoints)\n", arg);
  }
  return 0;
}

static int cmd_x(char *args) {
  char *arg1 = strtok(NULL, " ");

/* 检查是否没有给定参数，如果是，则遍历所有命令并输出每个命令的名称和描述。 
 * 如果给定了参数，则遍历 cmd_table 查找匹配的命令，然后输出该命令的名称和描述。
 * 如果未找到匹配的命令，则输出一条提示信息表明未知的命令。
 */
  if (arg1 == NULL) {
    /* no argument given */
    printf("Please enter the right argument, Usage: x N EXPR\n");
    return 0;
  }
  char *arg2 = strtok(NULL, " ");
  if (arg2 == NULL)
  {
    printf("Please enter the right argument, Usage: x N EXPR\n");
    return 0;
  }
/* strtol 函数将子字符串转换为长整型数。
 * 函数原型 long int strtol(const char *str, char **endptr, int base);
 * str：要被转换为长整型数的字符串。
 * endptr：这是一个指向字符指针的指针。在调用后，该指针将指向输入字符串中数字后的第一个字符。
 * base：指定要使用的数字基数（例如，10 表示十进制，16 表示十六进制）。
 */
  int n = strtol(arg1, NULL, 10);
  bool success;
  word_t res = expr(arg2, &success);
  if (!success) {
    printf(ANSI_FMT("invalid expression\n", ANSI_FG_RED));
    return 0;
  } 

  int i, j;
  for ( i = 0; i < n; i++)
  {
    for ( j = 0; j < 4; j++)
    {
      // printf(ANSI_FMT("%#08x: ", ANSI_FG_GREEN), expr);
      // 这里用ANSI_FMT宏改变输出字体前景色为绿色，并调整输出格式为没4位16进制书中间加下划线
      printf(ANSI_FMT("0x%04x_%04x: ", ANSI_FG_GREEN), (res >> 16) & 0xFFFF, res & 0xFFFF);
      word_t w = vaddr_read(res, 4);
      res += 4;
      // printf("%#08x\n", w);
      printf("%04x_%04x h\n", (w >> 16) & 0xFFFF, w & 0xFFFF);
    }
  }
  return 0;
}

/* 计算表达式的值*/
static int cmd_p(char* args){
  bool success;
  word_t res = expr(args, &success);
  if (!success) {
    printf(ANSI_FMT("invalid expression\n", ANSI_FG_RED));
  } else {
    printf("%u\n", res);
  }
  return 0;
}

/* 创建观察点*/
static int cmd_w(char* args){
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
     printf("Usage: w EXPR\n");
     return 0;    
  } 

  bool success;
  word_t res = expr(args, &success);
  if (!success) {
    printf(ANSI_FMT("Invalid expression\n", ANSI_FG_RED));
  } else
  {
    wp_watch(args, res);
  }
  return 0;
}

/* 删除观察点 */
static int cmd_d(char* args){
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
     printf("Usage: d N\n");
     return 0;    
  } 

  int no = strtol(arg, NULL, 10);
  wp_remove(no);
  return 0;
}

/* 定义了一个静态结构体数组 cmd_table，用于存储命令名称、描述以及处理函数的信息。
 * 每当新实现一条命令，需要先在cmd_table里面注册命令。
*/
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Usage: si N. Step program until it reaches a different source line", cmd_si },
  { "info", "Usage: info r. List of integer registers and their contents, for selected stack frame. "\
            "info w. Status of all watchpoints", cmd_info },
  { "x", "Usage: x N EXPR. Scan and view the data in memory", cmd_x },
  { "p", "Usage: p EXPR. Calculate the expression", cmd_p },
  { "w", "Usage: w EXPR. Watch for the variation of the expr result, pause at variation point.", cmd_w },
  { "d", "Usage: d N. Delete the watchpoints of wp.NO=N", cmd_d } 

  /* TODO: Add more commands */

};

/* 计算结构体数组长度 */
#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  /* 检查是否没有给定参数，如果是，则遍历所有命令并输出每个命令的名称和描述。 
  * 如果给定了参数，则遍历 cmd_table 查找匹配的命令，然后输出该命令的名称和描述。
  * 如果未找到匹配的命令，则输出一条提示信息表明未知的命令。
  */
  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    /* strtok 函数通过不断修改输入字符串，在每次调用时返回不同的子字符串，从而实现字符串的分割功能。
     * 在多线程环境下，strtok 函数并不是线程安全的，可以考虑使用 strtok_r 或其他线程安全的替代函数。
     * 第一个参数为待分割的字符串，第一次调用时传入要被分割的字符串，后续调用传入NULL。第二个参数为分隔符。、
     * 这里如果未传参则由rl_gets()函数一直循环读取命令行参数。
    */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    /* args为第二个参数的起始地址，这里加1是因为有分隔符（空格）*/
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        /* 如果命令返回值不小于0, 则退出此次循环，进入下一次循环*/
        if (cmd_table[i].handler(args) < 0) {
          if (strcmp(cmd, "q") == 0)
          {
            nemu_state.state = NEMU_QUIT;   // is_exit_status_bad()函数会返回0, 程序正常退出，否则报错。
          }
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();
  
  /* test expr, just for debug*/
  // test_expr();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
