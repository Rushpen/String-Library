#include "s21_strchr_test.h"

START_TEST(s21_strchr_test_1) {
  ck_assert_ptr_eq(s21_strchr("\0", 'c'), strchr("\0", 'c'));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  ck_assert_ptr_eq(s21_strchr("", 'c'), strchr("", 'c'));
}
END_TEST

START_TEST(s21_strchr_test_3) {
  ck_assert_ptr_eq(s21_strchr("aacaaac", 'c'), strchr("aacaaac", 'c'));
}
END_TEST

START_TEST(s21_strchr_test_4) {
  ck_assert_ptr_eq(s21_strchr("c", 'c'), strchr("c", 'c'));
}
END_TEST

START_TEST(s21_strchr_test_5) {
  ck_assert_pstr_eq(s21_strchr("c", 0), strchr("c", 0));
}
END_TEST

Suite *s21_strchr_suite_create(void) {
  Suite *suite = suite_create("s21_strchr_suite");
  TCase *tcase_core = tcase_create("s21_strchr_tcase");

  tcase_add_test(tcase_core, s21_strchr_test_1);
  tcase_add_test(tcase_core, s21_strchr_test_2);
  tcase_add_test(tcase_core, s21_strchr_test_3);
  tcase_add_test(tcase_core, s21_strchr_test_4);
  tcase_add_test(tcase_core, s21_strchr_test_5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
