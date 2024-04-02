#include "s21_memcpy_test.h"

START_TEST(s21_memcpy_test_1) {
  const char* src = "\0";
  char dest[1] = "x";
  s21_memcpy(dest, src, 0);
  ck_assert_mem_eq(dest, "x", 1);
}
END_TEST

START_TEST(s21_memcpy_test_2) {
  const char* src = "";
  char dest[2] = "x";
  s21_memcpy(dest, src, 1);
  ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(s21_memcpy_test_3) {
  const char* src = "abc";
  char dest[4] = "xyz";
  s21_memcpy(dest, src, 3);
  ck_assert_str_eq(dest, "abc");
}
END_TEST

START_TEST(s21_memcpy_test_4) {
  const char* src = "abc";
  char dest[4] = "xyz";
  s21_memcpy(dest, src, 2);
  ck_assert_str_eq(dest, "abz");
}
END_TEST

Suite* s21_memcpy_suite_create(void) {
  Suite* suite = suite_create("s21_memcpy_suite");
  TCase* tcase_core = tcase_create("s21_memcpy_tcase");

  tcase_add_test(tcase_core, s21_memcpy_test_1);
  tcase_add_test(tcase_core, s21_memcpy_test_2);
  tcase_add_test(tcase_core, s21_memcpy_test_3);
  tcase_add_test(tcase_core, s21_memcpy_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}