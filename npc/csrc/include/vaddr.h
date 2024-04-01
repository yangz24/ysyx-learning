/******************************************************
 * vaddr.h包含在npc虚拟内存中"取指令","读写虚拟内存"的函数声明
*******************************************************/

#ifndef __MEMORY_VADDR_H__
#define __MEMORY_VADDR_H__

#include "common.h"

word_t vaddr_ifetch(vaddr_t addr, int len);
word_t vaddr_read(vaddr_t addr, int len);
void vaddr_write(vaddr_t addr, int len, word_t data);


#endif
