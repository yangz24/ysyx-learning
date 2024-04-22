#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    // switch (c->mcause) {
    //   case 0xb : ev.event = EVENT_YIELD; c->mepc +=4; break;
    //   default: ev.event = EVENT_ERROR; break;
    // }
    switch (c->mcause)
    {
    case 0xb:
      if (c->GPR1 == -1) ev.event = EVENT_YIELD;
      else ev.event = EVENT_SYSCALL;
      c->mepc +=4;
      
      break;
    default: ev.event = EVENT_ERROR; break;
    }
    printf("mcause = %x, a5 = %x\n",c->mcause, c->GPR1);
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  // 声明一个Context指针context, 指向栈的末尾, 用于存储该线程上下文栈的起始地址
  Context *context = (Context*)(kstack.end - sizeof(Context));

  // 栈的底部为entry
  context->mepc = (uintptr_t)entry;

  // 设置mstatus=0x1800,使得difftest正常工作
  context->mstatus = 0x1800;

  // 设置参数, 使用a0-a7传递参数
  context->GPR2 = (uintptr_t)arg;

  // 返回上下文结构体指针
  return context;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
