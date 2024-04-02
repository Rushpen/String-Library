#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t flag = 0;
  unsigned char *ret;
  if (str == NULL) {
    flag = 1;

  } else {
    s21_size_t i = 0;
    s21_size_t mem = s21_strlen(str) + 1;
    ret = malloc(mem * sizeof(char));
    s21_memcpy(ret, str, mem);

    while (ret[i]) {
      if (ret[i] >= 97 && ret[i] <= 122) ret[i] -= 32;
      i++;
    }
  }
  return flag == 0 ? ret : NULL;
}
