#include "../s21_string.h"

s21_size_t is_delim(char c, const char* delim) {
  s21_size_t result = 0;
  while (*delim != '\0') {
    if (c == *delim) {
      result = 1;
      break;
    }
    delim++;
  }

  return result;
}

char* s21_strtok(char* srcString, const char* delim) {
  static char* backup_string;
  if (!srcString) {
    srcString = backup_string;
  }
  if (!srcString) {
    return 0;
  }
  while (1) {
    if (is_delim(*srcString, delim)) {
      srcString++;
      continue;
    }
    if (*srcString == 0) {
      return 0;
    }
    break;
  }
  char* ret = srcString;
  while (1) {
    if (*srcString == 0) {
      backup_string = srcString;
      return ret;
    }
    if (is_delim(*srcString, delim)) {
      *srcString = 0;
      backup_string = srcString + 1;
      return ret;
    }
    srcString++;
  }
}