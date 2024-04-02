#include "../s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {  // 12
  char* result = NULL;
  if (s21_strcspn(str1, str2) != s21_strlen(str1)) {
    result = (char*)str1 + s21_strcspn(str1, str2);
  }

  return result;
}