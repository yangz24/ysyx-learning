#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static int int2str(int n, char *s, int base);

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}
/**
 * @brief 将格式化的数据写入到指定的字符串缓冲区（不是标准输出流）
 * @param out 存储格式化后的字符串的缓冲区
 * @param fmt 格式化字符串
 * @param ... 可变参数列表
 * @return 写入缓冲区的字符数
*/
int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  int len = 1024;

  return vsnprintf(out, len, fmt, ap);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}
/**
 * @brief 将格式化的数据写入字符数组，指定最大写入的字符数目，与寻传递可变参数列表
 * @param out 存储格式化后的字符串的缓冲区
 * @param n 指定存储空间大小，防止发生缓冲区溢出
 * @param fmt 格式化字符串，包含格式说明符和文本内容
 * @param ap 是一个va_list类型，用于处理可变参数列表
 * @return out - start 返回实际写入缓冲区的字符数，不包括终止符\0
*/
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  char* start = out;
  while (n-- && *fmt)
  {
        if (*fmt != '%')
        {
          *out++ = *fmt;
        } else
          {
            switch (*(++fmt))
            {
            case 's': char* s = va_arg(ap, char*); while (*s != '\0') *out++ = *s++; break; // string
            case 'c': char c = (char)va_arg(ap, int); *out++ = c; break; // char
            case '%': *out++ = '%';  break;                  // 转义
            case 'd': int d = va_arg(ap, int);  out += int2str(d, out, 10); break; // 整数
            default: return -1;
            }
          }
        fmt++;
  }
  *out = '\0';
  va_end(ap);
  return out - start;
}
/**
 * @brief 颠倒字符串的字符
 * @param s 待颠倒的字符串
 * @param len 字符串的长度
 * @return 无返回值
*/
static void reverse(char *s, int len) {
  char *end = s + len - 1;
  char tmp;
  while (s < end) {
    tmp = *s;
    *s++ = *end;
    *end-- = tmp;
  }
}
/**
 * @brief 将给定进制的整数转化为字符串存储在给定地址中
 * @param n 给定字符串
 * @param s 给定字符地址
 * @param base 给定进制
 * @return int i 字符串长度
*/
static int int2str(int n, char *s, int base) {
  assert(base <= 16);

  int i = 0, sign = n, bit;
  // 若n为负数，转化为正数处理，后面再处理符号
  if (sign < 0) n = -n;
  do {
    bit = n % base;
    // 将每一位的数字通过加上基准字符的ascii码转化为字符
    if (bit >= 10) s[i++] = 'a' + bit - 10;
    else s[i++] = '0' + bit;  // 字符'0'的ascii码为48, 这里也可以用 s[i++] = 48 + bit;
  } while ((n /= base) > 0);
  // 加上符号位
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  // 反转生成的字符串，确保生成的字符串保持正确顺序
  reverse(s, i);

  return i;
}

#endif
