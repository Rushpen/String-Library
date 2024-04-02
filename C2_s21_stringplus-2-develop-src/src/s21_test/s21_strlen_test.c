#include "s21_strlen_test.h"

START_TEST(s21_strlen_test_1) {
  ck_assert_uint_eq(s21_strlen("\0"), strlen("\0"));
}
END_TEST

START_TEST(s21_strlen_test_2) { ck_assert_uint_eq(s21_strlen(""), strlen("")); }
END_TEST

START_TEST(s21_strlen_test_3) {
  ck_assert_uint_eq(s21_strlen("aaaaa"), strlen("aaaaa"));
}
END_TEST

START_TEST(s21_strlen_test_4) {
  ck_assert_uint_eq(s21_strlen("qqqqqqqqqqqqqqqqqqqqqqqq"),
                    strlen("qqqqqqqqqqqqqqqqqqqqqqqq"));
}
END_TEST

Suite *s21_strlen_suite_create(void) {
  Suite *suite = suite_create("s21_strlen_suite");
  TCase *tcase_core = tcase_create("s21_strlen_tcase");

  tcase_add_test(tcase_core, s21_strlen_test_1);
  tcase_add_test(tcase_core, s21_strlen_test_2);
  tcase_add_test(tcase_core, s21_strlen_test_3);
  tcase_add_test(tcase_core, s21_strlen_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
