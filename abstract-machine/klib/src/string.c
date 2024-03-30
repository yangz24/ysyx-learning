#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
// 计算字符串长度
size_t strlen(const char *s) {
  const char *str = s;
  while (*str)
  {
    str++;
  }
  return str - s;  
}
// 复制字符串到目标地址，返回目标地址
char *strcpy(char *dst, const char *src) {
  char *d = dst;
  const char *s = src;
  while (*s)
  {
    *d++ = *s++;
  }
  *d = '\0';
  return dst;
}
// 将源字符串的最多n个字符（若源字符串长度不足n,则填充null）复制到目标字符串中
char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  char *ret = dst;
  
  for (i = 0; i < n && *src != '\n'; i++)
  {
    *ret++ = *src++;
  }

  if (i < n)
  {
    while (i < n)
    {
      *ret++ = '\n';
      i++;
    }
  }
  return dst;
}
// 将源字符串加到目标字符串的末尾
char *strcat(char *dst, const char *src) {
  char *d = dst;

  // 定位目标字符串末尾
  while (*d)
  {
    d++;
  }

  // 逐个复制源字符串字符到目标字符串末尾
  while (*src)
  {
    *d++ = *src++;
  }
  
  *d = '\0';
  return dst;
}
// 比较两个字符串是否相等，返回0则相等
int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2))
  { 
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
  
}
// 比较两个字符串前n个字符是否相等，相等返回0
int strncmp(const char *s1, const char *s2, size_t n) {
  while (n && *s1 && (*s1 == *s2))
  {
    s1++;
    s2++;
    n--;
  }

  if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
  {
    return 0;
  }
  
  return (unsigned char)*s1 - (unsigned char)*s2;
}
// 将const c填充到n个字节的内存地址s处
void *memset(void *s, int c, size_t n) {
  unsigned char* start = (unsigned char*)s;
  unsigned char value = (unsigned char)c;

  while (n--)
  {
    *start++ = value;
  }
  return s;
}
/* *
 * @brief 此函数将源地址n个字节的数据复制到目标地址。
 * 考虑了内存区域重叠的情况，比memcpy更加安全。
 * @param dst 目标地址的指针
 * @param src 源地址的指针
 * @param n 待复制的字节数
 * @return dst 返回目标地址
 * @note 若源或目标为空指针，行为未定义.
*/
void *memmove(void *dst, const void *src, size_t n) {
  char* d = dst;
  const char* s = src;
  // 若源和目的相同，则无需移动
  if (d == s)
  {
    return dst;
  }
  // 检查源内存区域与目的内存区域是否重叠，若重叠则反向将数据由源复制到目标
  if (s < d && s + n > d)
  {
    for (size_t i = n; i > 0; i--) 
    {
      d[i-1] = s[i-1];
    }
  }
  else
  {
   for (size_t i = 0; i < n; i++)
   {
      d[i] = s[i];
   }
  }
  return dst;  
}
/* *
 * @brief 用于将源内存区域的内容直接复制到目标内存区域。
 * 不考虑源和目的区域重叠，所以更加高效，若考虑有重叠的情况，使用memmove函数。
 * @param out 目标地址
 * @param in 源地址
 * @param n 待复制字节数
 * @return out 返回目标地址
*/
void *memcpy(void *out, const void *in, size_t n) {
  char* dst = out;
  const char* src = (const char*)in;

  while (n-- && *src)
  {
    *dst++ = *src++;
  }
  *dst = '\n';
  return out;
}
/**
 * @brief 比较两个内存区域的前 n 个字节内容。
 * @param s1 第一个内存区域的起始地址
 * @param s2 第二个内存区域的起始地址
 * @param n 要比较的字节数
 * @return 
 *   返回值 < 0：s1 中第一个不等于 s2 的字符小于 s2 中对应位置的字符
 *   返回值 = 0：s1 和 s2 的前 n 个字节完全相等
 *   返回值 > 0：s1 中第一个不等于 s2 的字符大于 s2 中对应位置的字符
 */
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char* src1 = s1;
  const unsigned char* src2 = s2;
  
  while (n){
    if (*src1 != *src2)
    {
      return *src1 - *src2;
    }
    src1++;
    src2++;
    n--;
  }  
  return 0;
}

#endif
