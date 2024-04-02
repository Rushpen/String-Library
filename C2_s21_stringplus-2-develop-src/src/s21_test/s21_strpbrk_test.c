#include "s21_strpbrk_test.h"

START_TEST(s21_strpbrk_test_1) {
  const char* str = "abcdef";
  const char* charset = "cde";

  char* expected = strpbrk(str, charset);
  char* result = s21_strpbrk(str, charset);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_2) {
  const char* str = "abcdef";
  const char* charset = "xyz";

  char* expected = strpbrk(str, charset);
  char* result = s21_strpbrk(str, charset);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_3) {
  const char* str = "abcdef";
  const char* charset = "abc";

  char* expected = strpbrk(str, charset);
  char* result = s21_strpbrk(str, charset);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* s21_strpbrk_suite_create(void) {
  Suite* suite = suite_create("s21_strpbrk_suite");
  TCase* tcase_core = tcase_create("s21_strpbrk_tcase");

  tcase_add_test(tcase_core, s21_strpbrk_test_1);
  tcase_add_test(tcase_core, s21_strpbrk_test_2);
  tcase_add_test(tcase_core, s21_strpbrk_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}