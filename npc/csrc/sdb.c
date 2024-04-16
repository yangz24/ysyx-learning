/****************************************************
 *
 ****************************************************/

#include "include/vaddr.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "include/utils.h"

extern void cpu_exec(uint64_t n);
extern void reg_display();
static int cmd_help(char *args);


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
  line_read = readline("(npc) ");
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
    printf("Usage: si N (n <= 10).");
    return 0;
  }
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
/* 检查是否没有给定参数，如果是，则打印需要参数的提示信息。
 * 如果给定了参数，且参数为r，则打印寄存器状态，若参数为w, 则打印观测点信息。
 */
  if (arg == NULL) {
     printf("Usage: info r (registers)\n");
     return 0;    
  } 
  else if (strcmp(arg, "r") == 0) {
     reg_display();
  }
  else {
     printf("Unknown command '%s'\nUsage: info r (registers)\n", arg);
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
  word_t res = strtol(arg2, NULL, 16);

  int i, j;
  for ( i = 0; i < n; i++)
  {
    for ( j = 0; j < 4; j++)
    {
      printf("0x%04x_%04x: ", (res >> 16) & 0xFFFF, res & 0xFFFF);
      word_t w = vaddr_read(res, 4);
      res += 4;
      printf("%04x_%04x h\n", (w >> 16) & 0xFFFF, w & 0xFFFF);
    }
  }
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
  { "q", "Exit NPC", cmd_q },
  { "si", "Usage: si N. Step program until it reaches a different source line", cmd_si },
  { "info", "Usage: info r. List of integer registers and their contents, for selected stack frame. ", cmd_info },
  { "x", "Usage: x N EXPR. Scan and view the data in memory", cmd_x },

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

extern int is_batch_mode;

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* strtok 函数通过不断修改输入字符串，在每次调用时返回不同的子字符串，从而实现字符串的分割功能。
     * 在多线程环境下，strtok 函数并不是线程安全的，可以考虑使用 strtok_r 或其他线程安全的替代函数。
     * 第一个参数为待分割的字符串，第一次调用时传入要被分割的字符串，后续调用传入NULL。第二个参数为分隔符。、
     * 这里如果未传参则由rl_gets()函数一直循环读取命令行参数。
    */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* args为第二个参数的起始地址，这里加1是因为有分隔符（空格）*/
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        /* 如果命令返回值不小于0, 则退出此次循环，进入下一次循环*/
        if (cmd_table[i].handler(args) < 0) {
          if (strcmp(cmd, "q") == 0)
          { if (npc_state.state == NPC_ABORT || npc_state.state == NPC_END) return;
            npc_state.state = NPC_QUIT;   // is_exit_status_bad()函数会返回0, 程序正常退出，否则报错。
          }
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}
/* 调用sdb */
void engine_start() {
  /* Receive commands from user. */
  sdb_mainloop();
}