#include "s21_strchr_test.h"

START_TEST(s21_strrchr_test_1) {
  ck_assert_ptr_eq(s21_strrchr("\0", 'c'), strrchr("\0", 'c'));
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  ck_assert_ptr_eq(s21_strrchr("", 'c'), strrchr("", 'c'));
}
END_TEST

START_TEST(s21_strrchr_test_3) {
  ck_assert_ptr_eq(s21_strrchr("aacaaac", 'c'), strrchr("aacaaac", 'c'));
}
END_TEST

START_TEST(s21_strrchr_test_4) {
  ck_assert_ptr_eq(s21_strrchr("c", 'c'), strrchr("c", 'c'));
}
END_TEST

Suite *s21_strrchr_suite_create(void) {
  Suite *suite = suite_create("s21_strrchr_suite");
  TCase *tcase_core = tcase_create("s21_strrchr_tcase");

  tcase_add_test(tcase_core, s21_strrchr_test_1);
  tcase_add_test(tcase_core, s21_strrchr_test_2);
  tcase_add_test(tcase_core, s21_strrchr_test_3);
  tcase_add_test(tcase_core, s21_strrchr_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
