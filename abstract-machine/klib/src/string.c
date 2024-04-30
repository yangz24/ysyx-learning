#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while(s[len] != '\0'){
    len ++;
  }
  return len;
}
//不考虑越界行为
char *strcpy(char *dst, const char *src) {
  size_t i = 0;
  while(src[i] != '\0'){
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i = 0;
  for(; (i < n) && (src[i] != '\0'); i++){
    dst[i] = src[i];
  }
  for(; i < n; i++){
    dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t i = 0;
  size_t len_dst = 0;
  while(dst[len_dst] != '\0'){
    len_dst ++;
  }
  while(src[i] != '\0'){
    dst[len_dst + i] = src[i];
    i++;
  }
  dst[len_dst + i] = '\0';
  return dst;
}
//strcmp函数是两个字符串自左向右逐个字符相比（按 ASCII 值大小相比较）
//直到出现不同的字符或遇 \0 为止，如果字符全部相等，就比较字符串长度，字符串长度也相等时，两个字符串相等
int strcmp(const char *s1, const char *s2) {
  size_t i = 0;
  while(s1[i] != '\0' && s2[i] != '\0'){
    if (s1[i] == s2[i]){
      i++;
      continue;
    }
    else if(s1[i] > s2[i]){
      return 1;
    }
    else if(s1[i] < s2[i]){
      return -1;
    }
  }
  if(s1[i] == '\0' && s2[i] == '\0'){
    return 0;
  }
  else if(s1[i] == '\0' && s2[i] != '\0'){
    return -1;
  }
  else if(s2[i] == '\0' && s1[i] != '\0'){
    return 1;
  }
  return 0;
}


int strncmp(const char *cs, const char *ct, size_t count)
{
  signed char __res = 0;
  while (count) {
    if ((__res = *cs - *ct++) != 0 || !*cs++) {
      break;
    }
    count --;
  }
  return __res;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char *)s;
  for(size_t i = 0; i < n; i++){
    p[i] = (unsigned char)c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *str1 = (char *)dst;
  const char *str2 = (const char *)src;
  if(str1 > str2 && str1 < str2 + n){
    for(size_t i = n ; i > 0 ; i--){
      str1[i-1] = str2[i-1];
    }
  }
  else {
    for(size_t i = 0 ; i < n ; i++){
      str1[i] = str2[i];
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  char *str1 = (char *)out;
  const char *str2 = (const char *)in;
  for(size_t i = 0; i < n; i++){
    str1[i] = str2[i];
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *str1 = (const char *)s1;
  const char *str2 = (const char *)s2;
  for(size_t i = 0; i < n; i++){
    if(str1[i] < str2[i]){
      return -1;
    }
    else if(str1[i] > str2[i]){
      return 1;
    }
  }
  return 0;
}

#endif
