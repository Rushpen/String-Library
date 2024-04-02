#include "../s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {  // 1
  void* result = NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (((unsigned char*)str)[i] == c) {
      result = (void*)(str + i);
      break;
    }
  }

  return result;
}