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

#include "sdb.h"

#define NR_WP 32

void isa_watchpoint_display();

/* 定义了一个名为 watchpoint 的结构体，并通过 typedef 关键字创建了类型别名 WP。
 * int NO：整型成员 NO 用于存储观察点的编号。
 * struct watchpoint *next：指针成员 next 用于指向下一个观察点，这样可以形成一个链表结构。
 * char expr[1024] 存储输入的表达式
 * 存储表达式对应的值
*/
typedef struct watchpoint {
  int NO;     // 观测点编号
  struct watchpoint *next;  // 指针指向下一个观测点
  char expr[1024];    // 输入的表达式
  word_t old;    // 表达式对应的值
  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
/* 定义了两个静态指针变量 head 和 free_，分别用于表示链表的头指针和空闲对象的起始位置。 */
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

/* 将 head 指针设置为 NULL，表示链表为空。
 * 将 free_ 指针指向 wp_pool，表示所有对象都是可用的。
*/
  head = NULL;
  free_ = wp_pool;
}


/* 创建一个观察点*/
static WP* new_wp(){
  assert(free_);
  /* 池中可用观察点-1*/
  WP* ret = free_;
  free_ = free_->next;
  /* 从链表头部插入一个节点*/
  ret->next = head;
  head = ret;
  return ret;
}

static void free_wp(WP *wp){
  WP* h = head;
  if (h == wp){
    head = head->next;
    while (h && h->next != wp) h=h->next;
    free_ = h;
    return;
  }
  // if (h == wp) head = NULL;
  else {
    while (h && h->next != wp) h = h->next;
    assert(h);
    /* h指向原wp指向的下一个节点*/
    h->next = wp->next;
  }
  /* 池中可用观察点+1*/
  wp->next = free_;
  free_ = wp;
}

/* 若观察点池已满，则返回，否则使用new_wp()函数创建一个观察点并将表达式及其值传入*/  
void wp_watch(char *expr, word_t res) {
  if (free_ == NULL)
  {
    printf("Watch pool is fulfilled!\n");
    return; 
  }   
  WP* wp = new_wp();
  strcpy(wp->expr, expr);
  wp->old = res;
  printf("Watchpoint %d: %s = %d\n", wp->NO, wp->expr, wp->old);
}

/* 使用free_wp()函数删除一个观察点，若无观察点则返回提示*/
void wp_remove(int no) {
  if (head == NULL)
  {
    printf("Watch pool is empty!\n");
    return; 
  }  
  /* 若传入的观察点编号大于观察点池容量，则报错退出*/
  assert(no < NR_WP);
  WP* wp = &wp_pool[no];
  free_wp(wp);
  printf("Deleted watchpoint %d: %s\n", wp->NO, wp->expr);
}

void isa_watchpoint_display() {
  WP* h = head;
  if (!h)
  {
    printf("No watchpoints.\n");
    return;
  }
  printf(ANSI_FMT("%-16s%-16s%-16s\n", ANSI_FG_GREEN), "Num", "What", "Value");
  /* 遍历观察点链表并打印*/
  while (h)
  {
    printf("%-16d%-16s%-16d\n", h->NO, h->expr, h->old);
    h = h->next;
  }
}

void wp_difftest(){
  WP* h = head;
  /* 遍历观察点链表中所有节点吗*/
  while (h)
  {
    bool diff;
    word_t new = expr(h->expr, &diff);
    if (h->old != new)
    {
      /* 这里state置为NEMU_STOP后，将暂停程序运行*/
      nemu_state.state = NEMU_STOP;
      printf("Watchpoint %d: %s\n"
      "Old value = %u\n"
      "New value = %u\n"
      , h->NO, h->expr, h->old, new);
      h->old = new;
    }
    h = h->next;
  }
}