#include "s21_strncat_test.h"

START_TEST(s21_strncat_test_1) {
  char dest[12] = "Hello";
  const char* src = " World";
  s21_size_t n = 6;

  char expected[12] = "Hello World";
  char* result = s21_strncat(dest, src, n);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_strncat_test_2) {
  char dest[9] = "abc";
  const char* src = "defgh";
  s21_size_t n = 3;

  char expected[9] = "abcdef";
  char* result = s21_strncat(dest, src, n);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_strncat_test_3) {
  char dest[7] = "123";
  const char* src = "456";
  s21_size_t n = 3;

  char expected[7] = "123456";
  char* result = s21_strncat(dest, src, n);

  ck_assert_str_eq(result, expected);
}
END_TEST

Suite* s21_strncat_suite_create(void) {
  Suite* suite = suite_create("s21_strncat_suite");
  TCase* tcase_core = tcase_create("s21_strncat_tcase");

  tcase_add_test(tcase_core, s21_strncat_test_1);
  tcase_add_test(tcase_core, s21_strncat_test_2);
  tcase_add_test(tcase_core, s21_strncat_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}