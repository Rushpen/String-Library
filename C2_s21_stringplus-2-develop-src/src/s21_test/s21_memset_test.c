#include "s21_memset_test.h"

START_TEST(s21_memset_test_1) {
  char dest[1] = "x";
  ck_assert_ptr_eq(s21_memset(dest, '\0', 1), memset(dest, '\0', 1));
  ck_assert_int_eq(dest[0], '\0');
}
END_TEST

START_TEST(s21_memset_test_2) {
  char dest[1] = "x";
  ck_assert_ptr_eq(s21_memset(dest, 'A', 1), memset(dest, 'A', 1));
  ck_assert_str_eq(dest, "A");
}
END_TEST

START_TEST(s21_memset_test_3) {
  char dest[5] = "abcde";
  ck_assert_ptr_eq(s21_memset(dest, 'X', 3), memset(dest, 'X', 3));
  ck_assert_str_eq(dest, "XXXde");
}
END_TEST

START_TEST(s21_memset_test_4) {
  char dest[5] = "abcde";
  ck_assert_ptr_eq(s21_memset(dest, 'Z', 2), memset(dest, 'Z', 2));
  ck_assert_str_eq(dest, "ZZcde");
}
END_TEST

Suite* s21_memset_suite_create(void) {
  Suite* suite = suite_create("s21_memset_suite");
  TCase* tcase_core = tcase_create("s21_memset_tcase");

  tcase_add_test(tcase_core, s21_memset_test_1);
  tcase_add_test(tcase_core, s21_memset_test_2);
  tcase_add_test(tcase_core, s21_memset_test_3);
  tcase_add_test(tcase_core, s21_memset_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}