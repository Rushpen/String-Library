#include "../s21_string.h"
char* s21_strchr(const char* str, int c) {  // 6
  char* result = NULL;
  if (c == '\0') {
    result = "";
  } else {
    for (s21_size_t i = 0; str[i] != '\0'; i++) {
      if (str[i] == c) {
        result = (char*)str + i;
        break;
      }
    }
  }

  return result;
}