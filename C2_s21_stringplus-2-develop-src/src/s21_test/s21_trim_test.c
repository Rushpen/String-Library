#include "s21_trim_test.h"

START_TEST(s21_trim_test_1) {
  const char* original = "   Hello, world!   ";
  const char* s21_trim_chars = " ";

  const char* expected = "Hello, world!";
  void* result = s21_trim(original, s21_trim_chars);
  const char* result_str = (const char*)result;

  ck_assert_str_eq(result_str, expected);

  free(result);
}
END_TEST

START_TEST(s21_trim_test_2) {
  const char* original = "12345";
  const char* s21_trim_chars = " ";

  const char* expected = "12345";
  void* result = s21_trim(original, s21_trim_chars);
  const char* result_str = (const char*)result;

  ck_assert_str_eq(result_str, expected);

  free(result);
}
END_TEST

START_TEST(s21_trim_test_3) {
  const char* original = NULL;
  const char* s21_trim_chars = " ";

  void* result = s21_trim(original, s21_trim_chars);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_trim_test_4) {
  const char* original = "   Hello, world!   ";
  const char* s21_trim_chars = "xyz";

  const char* expected = "   Hello, world!   ";
  void* result = s21_trim(original, s21_trim_chars);
  const char* result_str = (const char*)result;

  ck_assert_str_eq(result_str, expected);

  free(result);
}
END_TEST

Suite* s21_trim_suite_create(void) {
  Suite* suite = suite_create("s21_trim_suite");
  TCase* tcase_core = tcase_create("s21_trim_tcase");

  tcase_add_test(tcase_core, s21_trim_test_1);
  tcase_add_test(tcase_core, s21_trim_test_2);
  tcase_add_test(tcase_core, s21_trim_test_3);
  tcase_add_test(tcase_core, s21_trim_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}