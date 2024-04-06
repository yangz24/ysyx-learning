/************************************************************
 * 通用的头文件和宏定义
*************************************************************/

/**
 * C/C++预处理指令,用于防止同一头文件被多次包含.
 * 它检查宏__COMMON_H__是否未定义,若未定义则定义
*/
#ifndef __COMMON_H__
#define __COMMON_H__

/* 标准库 */
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* 定义了一些实用的宏 */
#include "macro.h"

/* 调试相关的宏 */
#include "debug.h"

/* 手动维护的配置信息 */
#include "config.h"

/* 是否使用am中的klib库 */
#ifdef CONFIG_TARGET_AM
#include <klib.h>
#else
#include <assert.h>
#include <stdlib.h>
#endif


/* 重新定义了一些变量类型名 */
typedef uint32_t word_t;
typedef int32_t  sword_t;
#define FMT_WORD "0x%08" PRIx32

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08" PRIx32
typedef uint16_t ioaddr_t;


#endif
