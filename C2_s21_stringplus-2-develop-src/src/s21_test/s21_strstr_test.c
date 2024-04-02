#include "s21_strstr_test.h"

START_TEST(s21_strstr_test_1) {
  char* haystack = "abcdef";
  char* needle = "cd";

  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char* haystack = "abcdef";
  char* needle = "xyz";

  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char* haystack = "abcdef";
  char* needle = "abc";

  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* s21_strstr_suite_create(void) {
  Suite* suite = suite_create("s21_strstr_suite");
  TCase* tcase_core = tcase_create("s21_strstr_tcase");

  tcase_add_test(tcase_core, s21_strstr_test_1);
  tcase_add_test(tcase_core, s21_strstr_test_2);
  tcase_add_test(tcase_core, s21_strstr_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}