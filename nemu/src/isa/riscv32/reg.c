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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


/* 遍历整个寄存器数组，打印每个寄存器的值，分别以16进制，10进制输出
 * %-3s中，-表示左对齐，否则默认右对齐； 3表示每个字符串占据3个字符宽度。
 */
void isa_reg_display() {
  for (size_t i = 0; i < (sizeof(regs) / sizeof(regs[0])); i++)
  {
    printf(ANSI_FMT("%-3s\t", ANSI_FG_GREEN), regs[i]);
    printf("%#10x\t", gpr(i));
    printf("%d\n",  gpr(i));
  }
  
}

/* 这里通过遍历regs[]中定义的寄存器变量与传入的字符串比较（s+1是为了去除$符号），
 * 若相同则返回相应寄存器的值，不同则打印字符串本身。
*/
word_t isa_reg_str2val(const char *s, bool *success) {
  for (size_t i = 0; i < (sizeof(regs) / sizeof(regs[0])); i++)
  {
    if (strcmp(s+1,regs[i]) == 0)
    {
      *success = true;
      return gpr(i);
    }
  }
  *success = false;
  printf("s = %s\n", s);
  return 0;
}
