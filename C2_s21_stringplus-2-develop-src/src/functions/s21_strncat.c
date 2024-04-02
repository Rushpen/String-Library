#include <stddef.h>

#include "../s21_string.h"

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
  char* destEnd = dest + s21_strlen(dest);
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; ++i) {
    destEnd[i] = src[i];
  }

  destEnd[i] = '\0';  // Устанавливаем завершающий нуль

  return dest;
}