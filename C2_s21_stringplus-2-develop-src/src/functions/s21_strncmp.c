#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int comp = 0;
  if (str1 && str2 && n > 0) {
    for (size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        comp = str1[i] - str2[i];
        break;
      }
    }
  }

  return comp;
}