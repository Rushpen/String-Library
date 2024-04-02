#include "s21_insert_test.h"

START_TEST(s21_insert_test_1) {
  const char* original = "Hello, world!";
  const char* insert_str = "beautiful ";
  size_t start_index = 7;

  const char* expected = "Hello, beautiful world!";
  void* result = s21_insert(original, insert_str, start_index);
  const char* result_str = (const char*)result;

  ck_assert_str_eq(result_str, expected);

  free(result);
}
END_TEST

START_TEST(s21_insert_test_2) {
  const char* original = "12345";
  const char* insert_str = "abc";
  size_t start_index = 2;

  const char* expected = "12abc345";
  void* result = s21_insert(original, insert_str, start_index);
  const char* result_str = (const char*)result;

  ck_assert_str_eq(result_str, expected);

  free(result);
}
END_TEST

START_TEST(s21_insert_test_3) {
  const char* original = NULL;
  const char* insert_str = "test";
  size_t start_index = 0;

  void* result = s21_insert(original, insert_str, start_index);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST

Suite* s21_insert_suite_create(void) {
  Suite* suite = suite_create("s21_insert_suite");
  TCase* tcase_core = tcase_create("s21_insert_tcase");

  tcase_add_test(tcase_core, s21_insert_test_1);
  tcase_add_test(tcase_core, s21_insert_test_2);
  tcase_add_test(tcase_core, s21_insert_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}