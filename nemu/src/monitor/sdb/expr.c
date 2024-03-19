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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "sdb.h"

/* 定义了一个宏，用于区分传入的token属于哪个类*/
#define DEFTYPES(type, types) deftypes(type, types, ARRLEN(types))

bool check_parentheses(int p, int q);
int find_major(int p, int q);
void test_expr();
static word_t eval_operand(int i, bool *ok);
static word_t calc1(word_t val1, int op, word_t val2, bool *ok);
static word_t calc2(int op, word_t val, bool *ok);
word_t vaddr_read(vaddr_t addr, int len);

enum {
  TK_NOTYPE = 256,  // 空格
  TK_EQ,  // 双等号
  TK_NUM,  // 数字
  TK_REG, // 寄存器
  TK_NOEQ, // 不等于
  TK_LOGAND, // 逻辑与
  TK_LOGOR,  // 逻辑或
  TK_LT,     // 小于
  TK_GT,     // 大于
  TK_LE,     // 小于等于
  TK_GE,     // 大于等于
  TK_POS,    // 正号
  TK_NEG,    // 负号
  TK_DEREF   // 指针解引用
  /* TODO: Add more token types */
};

static int bound_types[] = {')',TK_NUM,TK_REG}; // boundary for binary operator
static int nop_types[] = {'(',')',TK_NUM,TK_REG}; // not operator type
static int op1_types[] = {TK_NEG, TK_POS, TK_DEREF}; // unary operator type

static bool deftypes(int type, int types[], int size) {
  for (int i = 0; i < size; i++) {
    if (type == types[i]) return true;
  }
  return false;
}

/* regex 表示正则表达式的字符串，token_type 表示该正则表达式对应的 token 类型。 */ 
static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {"0[xX][0-9a-fA-F]+|[0-9]+", TK_NUM},   // 匹配数字, 10进制或16进制
  {"\\$\\w+", TK_REG},  //匹配寄存器
  {"\\(", '('},          
  {"\\)", ')'},  
  {"\\+", '+'},         // plus
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"==", TK_EQ},        // equal
  {"!=", TK_NOEQ},
  {"&&", TK_LOGAND},   //逻辑与
  {"\\|\\|", TK_LOGOR},
  {" +", TK_NOTYPE},    // spaces
  {"<", TK_LT},         // 小于
  {">", TK_GT},         // 大于
  {"<=", TK_LE},        // 小于等于
  {">=", TK_GE},        // 大于等于
};

/* ARRLEN函数计算rules数组大小 */
#define NR_REGEX ARRLEN(rules)

/* re数组用于存储编译后的正则表达式对象 */
static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
/* init_regex 函数遍历 rules 数组中的每个规则，调用 regcomp 函数编译正则表达式，并将编译结果保存到 re[] 数组中。
 * 如果编译过程中出现错误，会调用 regerror 函数获取错误信息，并使用 panic 函数输出错误信息并终止程序执行。
*/
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {}; // __attribute__((used)) 是GNU 编译器的特性，在这里表示即使 tokens 没有被使用，也不要将其优化掉。
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;

  /* 用于存储正则表达式匹配结果的结构体。
   * regoff_t rm_so;：表示子字符串起始位置相对于字符串起始位置的字节偏移量。
   * regoff_t rm_eo;：表示子字符串结束位置相对于字符串起始位置的字节偏移量。
   */
  regmatch_t pmatch;

  /*记录检测到的token数量*/
  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      /* 给定正则表达式 re[i] 在字符串 e 从 position 开始匹配, 成功返回0, 并且匹配到的子字符串起始位置为0，说明整个字符串被匹配到。*/
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo - pmatch.rm_so;
        
        /* %.*s 表示输出制定长度的字符串，需要传两个参数，字符串长度和字符串起始地址 */
        printf("match rules[%d] = \"%s\" at position %d with len %d: %.*s\n",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        
        if (rules[i].token_type == TK_NOTYPE) break;

        tokens[nr_token].type = rules[i].token_type; 
        switch (rules[i].token_type) {
          case TK_NUM:
          case TK_REG:
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0'; 
            break;
          case '+':
          case '-':
          case '*':
            if (nr_token == 0 || !DEFTYPES(tokens[nr_token - 1].type, bound_types))
            {
              switch (rules[i].token_type) {
                case '+' : tokens[nr_token].type = TK_POS; break;
                case '-' : tokens[nr_token].type = TK_NEG; break;
                case '*' : tokens[nr_token].type = TK_DEREF; break;
                default : ;
              }
            }
            break; 
          default:;// TODO();
        }
        nr_token++;
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, ""); // ^：表示在之前输出的字符串中的指定位置下方标记。
      return false;
    }
  }
  return true;
}

word_t eval(int p, int q, bool *ok) {
  *ok = true;
  if (p > q) {
    *ok = false;
    return 0;
  } else if (p == q) {
      return eval_operand(p, ok);
  } else if (check_parentheses(p, q)) {  
    return eval(p+1, q-1, ok);
  } else {    
    int major = find_major(p, q);
    if (major < 0) {
      *ok = false;
      return 0;
    }

    /* 表达式由主运算符分为两个部分 */
    bool ok1, ok2;
    word_t val1 = eval(p, major-1, &ok1);
    word_t val2 = eval(major+1, q, &ok2);

    /* 若主运算符右边无表达式，则报错，例如 3 - */
    if (!ok2) {
      ok = false;
      return 0;
    } else if (ok1)
    {
      word_t ret = calc1(val1, tokens[major].type, val2, ok);
      return ret;
    } else {
      word_t ret = calc2(tokens[major].type, val2, ok);
      return ret;
    }   

  }
}

/* 去除括号 */
bool check_parentheses(int p, int q) {
  if (tokens[p].type=='(' && tokens[q].type==')') {
    int par = 0;
    for (int i = p; i <= q; i++) {
      if (tokens[i].type=='(') par++;
      else if (tokens[i].type==')') par--;

      if (par == 0) return i==q; // the leftest parenthese is matched
    }
  }
  return false;
}

/* 找出优先级最低的主运算符*/
int find_major(int p, int q) {
  int ret = -1, par = 0, op_pre = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') {
      par++;
    } else if (tokens[i].type == ')') {
      if (par == 0) {
        return -1;
      }
      par--;
    } else if (DEFTYPES(tokens[i].type, nop_types))
    {
      continue;
    } else if (par > 0) {
      continue;
    } else {
      int tmp_pre = 0;
      switch (tokens[i].type) {
      case TK_LOGOR: tmp_pre++;
      case TK_LOGAND: tmp_pre++;
      case TK_EQ:
      case TK_NOEQ: tmp_pre++;
      case TK_LT:
      case TK_GT:
      case TK_LE:
      case TK_GE: tmp_pre++;
      case '*': 
      case '/': tmp_pre++;
      case '+': 
      case '-': tmp_pre++;
      case TK_NEG:
      case TK_DEREF:
      case TK_POS: tmp_pre++; break;
      default: assert(0);
      }
      if (tmp_pre > op_pre || (tmp_pre == op_pre && !DEFTYPES(tokens[i].type, op1_types))) {
        op_pre = tmp_pre;
        ret = i;
      }
    }
  }
  if (par != 0) return -1;
  return ret;
}

static word_t eval_operand(int i, bool *ok) {
  switch (tokens[i].type)
  {
  case TK_NUM:
    /* strncmp比较两个字符串的前n个字符是否相同，相同返回0, 不相同则返回第一个不同字符出的ASCII值之差 */
    if (strncmp("0x", tokens[i].str, 2) == 0) return strtol(tokens[i].str, NULL, 16);
    else return strtol(tokens[i].str, NULL, 10); 
  case TK_REG:
    return isa_reg_str2val(tokens[i].str, ok);
  default:
    *ok = false;
    return 0;
  }
}

/* 算数或逻辑运算 */
static word_t calc1(word_t val1, int op, word_t val2, bool *ok) {
  switch (op)
  {
  case '+': return val1 + val2; break;
  case '-': return val1 - val2; break;
  case '*': return val1 * val2; break;
  case '/': if (val2 == 0){
              *ok = false;
              return 0;
            } else return val1 / val2; break;
  case TK_LOGAND: return val1 && val2; break;
  case TK_LOGOR: return val1 || val2; break;
  case TK_EQ: return val1 == val2; break;
  case TK_NOEQ: return val1 != val2; break;
  case TK_LT: return val1 < val2; break;
  case TK_GT: return val1 > val2; break;
  case TK_LE: return val1 <= val2; break;
  case TK_GE: return val1 >= val2; break;
  default: *ok = false; return 0;
  }
}

/* 单目运算 */
static word_t calc2(int op, word_t val, bool *ok) {
  switch (op)
  {
  case TK_POS: return val; break;
  case TK_NEG: return -val; break;
  case TK_DEREF: return vaddr_read(val, 4); break;
  default: *ok = false; break;
  }
  return 0;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  // TODO();
  return eval(0, nr_token-1, success);
}

/*===========================================================================================
 *这是一段测试代码，用来测试gen-expr生成的随即表达式计算的结果，是否与此处实现的表达式求职一致来验证功能。
 *可以通过取消掉init_sdb()里的test_expr()注释来调用。
 *===========================================================================================
*/
void test_expr() {
  FILE *fp = fopen("/home/ginoyang/ysyx-workbench/nemu/tools/gen-expr/build/input", "r");
  if (fp == NULL) printf(ANSI_FMT("Test_expr generation error", ANSI_FG_RED));

  char *e = NULL;
  word_t correct_res;
  size_t len = 0;
  ssize_t read;
  bool success = false;
  int invalid_input = 0;
  int mistake_times = 0;

  while (true) {
    if(fscanf(fp, "%u ", &correct_res) == -1) break;
    /* */
    read = getline(&e, &len, fp);
    e[read-1] = '\0'; //将读取的文本行末尾的换行符 '\n' 替换为字符串结束符 '\0'
    
    word_t res = expr(e, &success);
    if (success == false)
    {
      printf(ANSI_FMT("Invalid expression!\n", ANSI_FG_RED));
      invalid_input++;
    }
    // assert(success);
    if (res != correct_res) {
      printf(ANSI_FMT("%s\n", ANSI_FG_YELLOW), e);
      printf(ANSI_FMT("Expected: %u, got: %u\n", ANSI_FG_YELLOW), correct_res, res);
      mistake_times++;
    }
  }

  fclose(fp);
  if (e) free(e);

  Log("Expr test end. %d invalid input expression! %d test case fault!", invalid_input, mistake_times);
}