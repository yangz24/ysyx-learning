#include <common.h>

// 若开启了mtrace,则每次读内存时都会打印读地址和读字节长度
void display_pread(paddr_t addr, int len) {
    printf ("pread at " FMT_PADDR " len = %d\n", addr, len);
}
// 若开启了mtrace,则每次写内存时都会打印写地址,写字节长度以及写数据
void display_pwrite(paddr_t addr, int len, word_t data) {
    printf("pwrite at " FMT_PADDR " len = %d, data = " FMT_WORD "\n", addr, len, data);
}