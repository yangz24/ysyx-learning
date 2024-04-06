#include "include/utils.h"

#define MAX_TRACE_SIZE 16
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

typedef struct 
{
    word_t pc;
    uint32_t inst;
} ITraceNode;

ITraceNode iringbuf[MAX_TRACE_SIZE];
int head = 0;
int tail = 0;
bool full = false;

void trace_inst(word_t pc, uint32_t inst) {
    iringbuf[tail].pc = pc;
    iringbuf[tail].inst = inst;
    // 尾指针取模，确保不会访问溢出
    tail = (tail + 1) % MAX_TRACE_SIZE;
    if (tail == head)
    {
        full = true;
        head = (head + 1) % MAX_TRACE_SIZE;
    }
}

void display_trace() {
    // 果环形缓冲区未满且尾指针为 0，表示还没有记录指令，则直接返回，不进行指令展示。
    if (!full && tail == 0) return;
    // 根据环形缓冲区是否已满确定起始索引 idx。如果环形缓冲区已满，则从头指针 head 开始；否则从第一条记录开始展示。
    int idx = full? head : 0;
    // 用于存放pc, inst, 和反汇编后的字符串
    char buf[128]; 
    // 用于构建buf内的字符串
    char *p;
    printf("Recently executed instructions:\n");
    do
    {
        p = buf;
        // 将pc, inst打印到缓冲区
        p += sprintf(buf, "%s" FMT_WORD ": %08x ", ((idx+1) % MAX_TRACE_SIZE == tail)?" --> ":"     ", iringbuf[idx].pc, iringbuf[idx].inst);
        // 将反汇编结果打印到缓冲区inst后
        disassemble(p, buf+sizeof(buf)-p, iringbuf[idx].pc, (uint8_t*)&iringbuf[idx].inst, 4);
        // 指出第一个错误指令所在处，在终端出设置文本颜色为红色
        if ((idx+1) % MAX_TRACE_SIZE == tail) printf(ANSI_FG_RED); 
        puts(buf);
    } while ((idx = (idx+1) % MAX_TRACE_SIZE) != tail);
    // 重置终端文本颜色为默认值
    puts(ANSI_NONE);
}