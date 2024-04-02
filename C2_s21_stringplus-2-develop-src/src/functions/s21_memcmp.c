#include "../s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {  // 2
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (((unsigned char*)str1)[i] == ((unsigned char*)str2)[i]) continue;
    if (((unsigned char*)str1)[i] > ((unsigned char*)str2)[i]) {
      result = 1;
      break;
    } else {
      result = -1;
      break;
    }
  }

  return result;
}