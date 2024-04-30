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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static char *buf_start = NULL;
static char *buf_end = buf + sizeof(buf)/sizeof(buf[0]);

/* 生成小于n且不为0的随即数 */
static uint32_t choose(uint32_t n){
  uint32_t ret = 0; 
  while (ret == 0)
  {
    ret = rand() % n;
  }
  return ret;  
}

// static void gen_space(){
//   int size = choose(2);
//   if (buf_start < buf_end)
//   {
//    int n_wr = snprintf(buf_start, buf_end-buf_start, "%*s", size, " "); // %*s，表示使用额外参数写入size个空格到buf中
//    if (n_wr > 0)
//    {
//       buf_start += n_wr;
//    }
//   }
// }


static void gen_num() {
  int num = choose(100);
  if (buf_start < buf_end)
  {
    /* 向buf里写入不超过buf宽度的无符号整形数据num， 返回写入数的个数
     * 每循环一次buf剩余空间减少，重新计算起始地址和buf剩余宽度
     */
    int n_wr = snprintf(buf_start, buf_end - buf_start, "%u", num);
    if (n_wr > 0)
    {
      buf_start += n_wr;
    }
  }
  // gen_space();
} 

/* 生成字符，例如'(',')' 等*/
static void gen_char(char c) {
  if (buf_start < buf_end)
  {
    int n_wr = snprintf(buf_start, buf_end - buf_start, "%c", c);
    if (n_wr > 0)
    {
      buf_start += n_wr;
    }
  }
}

/* 通过gen_char函数将生成的随即运算符写进buf*/
static char ops[] = {'+', '-', '*', '/' };
static void gen_rand_op() {
  int op_index = choose(sizeof(ops));
  char op = ops[op_index];
  gen_char(op);
}


/* 递归生成随机表达式*/
static void gen_rand_expr() {
  switch (choose(4)) {
    case 1: gen_num(); break;
    case 2: gen_char('('); gen_rand_expr(); gen_char(')');   break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    /* sscanf与scanf类似，但它从字符串中读取格式化输入
     * 这里表示从命令行参数中读取一个整数，并存储到loop中
     */
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf_start = buf;
    gen_rand_expr();
    /* sprintf将格式化的数据写入到字符串缓冲区中，
     * code_buf为目标字符串缓冲区地址，
     * code_format为格式化字符串，用于指定要写入到缓冲区的内容，类似于printf中的格式字符串，
     * buf为要输出的内容，输出的格式由code_format定义。 
    */
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    /* 将code_buf指针指向的内容写入到fp指针指向的文件*/
    fputs(code_buf, fp);
    fclose(fp);

    /* system是调用系统命令，即执行其内编译命令， 返回退出状态码或错误码*/
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    /* 使用了 popen 函数来创建一个到另一个进程的管道，并打开一个文件流以便读取该进程的输出，
     * 其实就是执行了./tmp/.expr命令，并将输出通过管道重定向到fp文件中。
    */
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    /* 从文件流 fp 中读取一个整数值，并将该值存储在名为 result 的整型变量中，
     * 通过 ret 变量来检查读取操作是否成功。
    */
    uint32_t result;
    ret = fscanf(fp, "%u", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
