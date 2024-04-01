/******************************************
 * npc内存读写操作,要读写npc开辟的虚拟内存空间,
 * 就要先调用下面这三个函数.
*******************************************/

#include "include/paddr.h"

/* 从虚拟内存中取指令 */
word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

/* 从虚拟内存中读数据 */
word_t vaddr_read(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

/* 往虚拟内存写数据 */
void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_write(addr, len, data);
}
