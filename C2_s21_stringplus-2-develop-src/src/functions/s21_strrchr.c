#include "../s21_string.h"
char* s21_strrchr(const char* str, int c) {  // 6
  char* result = NULL;
  if (c == '\0') {
    result = "";
  } else {
    for (int i = s21_strlen(str) - 1; i >= 0; i--) {
      if (str[i] == c) {
        result = (char*)str + i;
        break;
      }
    }
  }

  return result;
}