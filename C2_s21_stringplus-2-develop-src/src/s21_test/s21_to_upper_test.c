#include "s21_to_upper_test.h"

START_TEST(s21_to_upper_test_1) {
  const char* original = "Hello, World!";
  char* expected = "HELLO, WORLD!";

  void* result = s21_to_upper(original);
  char* result_str = (char*)result;

  ck_assert_str_eq(result_str, expected);
  free(result);
}
END_TEST

START_TEST(s21_to_upper_test_2) {
  const char* original = "12345";

  void* result = s21_to_upper(original);
  char* result_str = (char*)result;

  ck_assert_str_eq(result_str, "12345");
  free(result_str);
}
END_TEST

START_TEST(s21_to_upper_test_3) {
  const char* original = NULL;

  void* result = s21_to_upper(original);

  ck_assert_ptr_eq(result, NULL);
}

END_TEST

Suite* s21_to_upper_suite_create(void) {
  Suite* suite = suite_create("s21_to_upper_suite");
  TCase* tcase_core = tcase_create("s21_to_upper_tcase");

  tcase_add_test(tcase_core, s21_to_upper_test_1);
  tcase_add_test(tcase_core, s21_to_upper_test_2);
  tcase_add_test(tcase_core, s21_to_upper_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}