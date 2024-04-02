#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int exit = 0;
  char *ret = NULL;
  if ((src != NULL) && (trim_chars != NULL)) {
    s21_size_t left = 0, right = s21_strlen(src);
    ret = (char *)calloc(s21_strlen(src) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(src) && !exit; i++) {
      for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
        exit = 1;
        if (src[i] == trim_chars[j]) {
          left++;
          exit = 0;
          break;
        }
      }
    }
    exit = 0;
    if (s21_strlen(src) > 0) {
      for (s21_size_t i = s21_strlen(src) - 1; i > 0 && !exit; i--) {
        for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
          exit = 1;
          if (src[i] == trim_chars[j]) {
            right--;
            exit = 0;
            break;
          }
        }
      }
    }
    for (s21_size_t i = left; i < right; i++) {
      ret[i - left] = src[i];
    }
  }

  return (void *)ret;
}