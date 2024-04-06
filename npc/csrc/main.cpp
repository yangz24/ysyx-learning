#include "include/sim.h"

extern VerilatedContext* contextp;
extern VerilatedVcdC* tfp;
extern VCPU* CPU;


extern void init_monitor(int argc, char *argv[]);
extern void engine_start();
extern int is_exit_status_bad();


int main(int argc, char *argv[]) {
  /* 打印传入的参数 */
  for (size_t i = 0; i < argc; i++)
  {
    printf("argc = %ld, argv = %s\n", i, argv[i]);
  }
  /* 初始化仿真环境 */
  sim_init();
  reset(10);
  /* 启动npc */
  init_monitor(argc, argv);
  engine_start();
  /* 退出仿真 */
  sim_exit();
  CPU->final();
  delete CPU;

  return is_exit_status_bad();
}
