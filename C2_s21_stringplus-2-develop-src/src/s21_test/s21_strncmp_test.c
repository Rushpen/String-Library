#include "s21_strncmp_test.h"

START_TEST(s21_strncmp_test_1) {
  const char* str1 = "abc";
  const char* str2 = "abc";
  s21_size_t n = 3;

  int expected = strncmp(str1, str2, n);
  int result = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_strncmp_test_2) {
  const char* str1 = "abcd";
  const char* str2 = "abce";
  s21_size_t n = 4;

  int expected = strncmp(str1, str2, n);
  int result = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_strncmp_test_3) {
  const char* str1 = "abc";
  const char* str2 = "abcd";
  s21_size_t n = 3;

  int expected = strncmp(str1, str2, n);
  int result = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_strncmp_test_4) {
  const char* str1 = "abce";
  const char* str2 = "abcd";
  s21_size_t n = 4;

  int expected = strncmp(str1, str2, n);
  int result = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(result, expected);
}
END_TEST

Suite* s21_strncmp_suite_create(void) {
  Suite* suite = suite_create("s21_strncmp_suite");
  TCase* tcase_core = tcase_create("s21_strncmp_tcase");

  tcase_add_test(tcase_core, s21_strncmp_test_1);
  tcase_add_test(tcase_core, s21_strncmp_test_2);
  tcase_add_test(tcase_core, s21_strncmp_test_3);
  tcase_add_test(tcase_core, s21_strncmp_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}