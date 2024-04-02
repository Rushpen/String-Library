#include "../s21_string.h"

char* s21_strstr(char* haystack, char* needle) {  // 14
  int nHay = s21_strlen(haystack);
  int nNee = s21_strlen(needle), found = 0, shift = 0;
  char* result;
  if (nNee == 0) return haystack;
  for (int i = 0; (i <= nHay - nNee) && !found; i++) {
    for (int j = 0; j < nNee; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
      if (j == nNee - 1) {
        found = 1;
        shift = i;
        break;
      }
    }
  }
  if (found) {
    result = haystack + shift;
  } else {
    result = 0;
  }

  return result;
}