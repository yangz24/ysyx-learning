#include <am.h>
#include <klib-macros.h>

void __am_timer_init();
void __am_gpu_init();
void __am_audio_init();
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);
void __am_audio_config(AM_AUDIO_CONFIG_T *);
void __am_audio_ctrl(AM_AUDIO_CTRL_T *);
void __am_audio_status(AM_AUDIO_STATUS_T *);
void __am_audio_play(AM_AUDIO_PLAY_T *);
void __am_disk_config(AM_DISK_CONFIG_T *cfg);
void __am_disk_status(AM_DISK_STATUS_T *stat);
void __am_disk_blkio(AM_DISK_BLKIO_T *io);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_UART_CONFIG_T *cfg)   { cfg->present = false; }
static void __am_net_config (AM_NET_CONFIG_T *cfg)    { cfg->present = false; }

/* 定义了一个新的类型 handler_t，它是一个指向函数的指针，这个函数没有返回值并接受一个指向任意类型的指针作为参数。
 * 在实际使用中，可以声明一个 handler_t 类型的变量，然后让它指向一个符合这种签名的函数。
 * 这在编写回调函数或事件处理函数时非常有用。
 */
typedef void (*handler_t)(void *buf);
/* 设备的回调函数索引 */
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_GPU_CONFIG  ] = __am_gpu_config,
  [AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
  [AM_GPU_STATUS  ] = __am_gpu_status,
  [AM_UART_CONFIG ] = __am_uart_config,
  [AM_AUDIO_CONFIG] = __am_audio_config,
  [AM_AUDIO_CTRL  ] = __am_audio_ctrl,
  [AM_AUDIO_STATUS] = __am_audio_status,
  [AM_AUDIO_PLAY  ] = __am_audio_play,
  [AM_DISK_CONFIG ] = __am_disk_config,
  [AM_DISK_STATUS ] = __am_disk_status,
  [AM_DISK_BLKIO  ] = __am_disk_blkio,
  [AM_NET_CONFIG  ] = __am_net_config,
};

static void fail(void *buf) { panic("access nonexist register"); }

/* 初始化IOE */
bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    // 如果 lut[i] 的值为空（即未设置），则将其设置为 fail 函数的地址。这样做是为了确保 lut 数组中的每个索引位置都有对应的处理函数。
    if (!lut[i]) lut[i] = fail;
  __am_gpu_init();
  __am_timer_init();
  __am_audio_init();
  return true;
}
/* 从编号为reg的寄存器中读出内容到缓冲区buf中 */
/* 函数的功能是根据传入的寄存器索引 reg，从预先定义的 lut 数组中找到对应索引位置的函数指针，然后调用该函数，并将 buf 作为参数传递给它。
 * lut[reg]：根据传入的 reg 参数，从 lut 数组中取出对应索引位置的函数指针。
 * (handler_t)：这是一个类型转换操作，将取出的函数指针转换为 handler_t 类型，即之前定义的函数指针类型。
 * ((handler_t)lut[reg])(buf)：通过将函数指针转换为 handler_t 类型，并将 buf 作为参数传递给它，调用了所指向的函数。
*/
void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
/* 往编号为reg寄存器中写入缓冲区buf中的内容 */
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
