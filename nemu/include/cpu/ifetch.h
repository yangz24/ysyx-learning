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

#ifndef __CPU_IFETCH_H__

#include <memory/vaddr.h>


/* 
 * 问: 在nemu/include/cpu/ifetch.h中, 你会看到由static inline开头定义的inst_fetch()函数. 
 * 分别尝试去掉static, 去掉inline或去掉两者, 然后重新进行编译, 你可能会看到发生错误. 请分别解释为什么这些错误会发生/不发生? 你有办法证明你的想法吗?
 * 答: 全部去掉后会报错，因为函数的定义在头文件，一旦超过一个文件包含，就会重复定义.而保留任何一个都不会出错。
 * 加入static不会报错，这样每次包含头文件，都会产生一个私有的函数。
 * 加入inline后也不会报错,编译时内联函数被打平，便不存在调用过程。
 * 关键字 inline 告诉编译器，任何地方只要调用内联函数，就直接把该函数的机器码插入到调用它的地方。这样程序执行更有效率，就好像将内联函数中的语句直接插入到了源代码文件中需要调用该函数的地方一样。
 * 这样，对与需要经常调用的函数来说，免去频繁的跳转，大大提升效率。 
*/
/* 取指令，更新pc值 */
static inline uint32_t inst_fetch(vaddr_t *pc, int len) {
  uint32_t inst = vaddr_ifetch(*pc, len);
  (*pc) += len;
  return inst;
}

#endif
