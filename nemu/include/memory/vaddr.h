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

#ifndef __MEMORY_VADDR_H__
#define __MEMORY_VADDR_H__

#include <common.h>

word_t vaddr_ifetch(vaddr_t addr, int len);
word_t vaddr_read(vaddr_t addr, int len);
void vaddr_write(vaddr_t addr, int len, word_t data);

/**
 * PAGE_SHIFT 定义了页大小的位移量，即将 1 左移 PAGE_SHIFT 位来计算页大小。在这里，PAGE_SHIFT 的值为 12，表示页大小为 2^12 = 4096 字节（4KB）。
 * PAGE_SIZE 定义了实际的页大小，通过将 1 左移 PAGE_SHIFT 位得到。在这里，PAGE_SIZE 的值为 4096 字节（4KB），即代表一个页面的大小。
 * PAGE_MASK 定义了用于页对齐操作的掩码。由于页大小通常是 2 的幂次方，减去 1 后可以得到一个二进制形式为末尾若干位为 1 的数字，例如对于 4KB 的页，PAGE_MASK 的值为 0xFFF。
*/
#define PAGE_SHIFT        12
#define PAGE_SIZE         (1ul << PAGE_SHIFT)  // 1ul：表示一个无符号长整型常量，其值为 1。ul 是后缀，表示这是一个无符号长整型数值。
#define PAGE_MASK         (PAGE_SIZE - 1)

#endif
