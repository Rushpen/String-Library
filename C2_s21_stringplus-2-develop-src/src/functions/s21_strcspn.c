#include "../s21_string.h"

s21_size_t s21_strcspn(const char* str1, const char* str2) {  // 9
  const char* char_str1 = (const char*)str1;
  const char* char_str2 = (const char*)str2;
  s21_size_t result = s21_strlen(str1);
  int notFound = 1;

  for (s21_size_t i = 0; (i < s21_strlen(str1)) && notFound; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (char_str1[i] == char_str2[j]) {
        result = i;
        notFound = 0;
        break;
      }
    }
  }

  return result;
}