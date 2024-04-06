#ifndef __ISA_H__
#define __ISA_H__

#include "common.h"

typedef struct 
{
    word_t gpr[32];
    vaddr_t pc;    
} CPU_state;



#endif