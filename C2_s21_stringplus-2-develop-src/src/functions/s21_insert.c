#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;

  if (str && src) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t size = src_len + str_len;
    s21_size_t i = start_index;
    s21_size_t j = str_len;
    s21_size_t g = src_len - i;

    if (src_len >= start_index) {
      result =
          (char *)calloc(size + 1, sizeof(char));  // +1 for null terminator

      if (result) {
        for (s21_size_t k = 0; k < i; ++k) {
          result[k] = src[k];
        }

        for (s21_size_t k = 0; k < j; ++k) {
          result[i + k] = str[k];
        }

        for (s21_size_t k = 0; k < g; ++k) {
          result[i + j + k] = src[i + k];
        }

        result[size] = '\0';
      }
    }
  }

  return result;
}