#include "s21_strncpy_test.h"

START_TEST(s21_strncpy_test_1) {
  char dest[10] = "12345";
  const char* src = "abc";
  s21_size_t n = 3;

  char* result = s21_strncpy(dest, src, n);

  ck_assert_str_eq(result, strncpy(dest, src, n));
}
END_TEST

START_TEST(s21_strncpy_test_2) {
  char dest[5] = "123";
  const char* src = "abcdef";
  s21_size_t n = 5;

  char* result = s21_strncpy(dest, src, n);

  ck_assert_str_eq(result, strncpy(dest, src, n));
}
END_TEST

START_TEST(s21_strncpy_test_3) {
  char dest[5] = "123";
  const char* src = "abcdef";
  s21_size_t n = 2;

  char* result = s21_strncpy(dest, src, n);

  ck_assert_str_eq(result, strncpy(dest, src, n));
}
END_TEST

Suite* s21_strncpy_suite_create(void) {
  Suite* suite = suite_create("s21_strncpy_suite");
  TCase* tcase_core = tcase_create("s21_strncpy_tcase");

  tcase_add_test(tcase_core, s21_strncpy_test_1);
  tcase_add_test(tcase_core, s21_strncpy_test_2);
  tcase_add_test(tcase_core, s21_strncpy_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}