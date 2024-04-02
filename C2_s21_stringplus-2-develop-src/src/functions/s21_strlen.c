#include "../s21_string.h"

s21_size_t s21_strlen(const char* c) {  // 11
  s21_size_t len = 0;
  while (c[len]) {
    len++;
  }

  return len;
}