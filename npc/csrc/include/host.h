/***********************************************
 * host.h 文件实际完成了在npc虚拟内存区域读写的操作
************************************************/

#ifndef __MEMORY_HOST_H__
#define __MEMORY_HOST_H__

#include "common.h"


/* 支持支持1、2、4、8字节读出数据*/
static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

/* 支持支持1、2、4、8字节写入数据*/
static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0);
  }
}

#endif
