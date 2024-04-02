#include "s21_strcspn_test.h"

START_TEST(s21_strcspn_test_1) {
  const char *str = "abcde123";
  const char *set = "123";
  s21_size_t expected = strcspn(str, set);
  s21_size_t result = s21_strcspn(str, set);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  const char *str = "abcde123";
  const char *set = "xyz";
  s21_size_t expected = strcspn(str, set);
  s21_size_t result = s21_strcspn(str, set);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  const char *str = "abcde123";
  const char *set = "xyz123";
  s21_size_t expected = strcspn(str, set);
  s21_size_t result = s21_strcspn(str, set);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *s21_strcspn_suite_create(void) {
  Suite *suite = suite_create("s21_strcspn_suite");
  TCase *tcase_core = tcase_create("s21_strcspn_tcase");

  tcase_add_test(tcase_core, s21_strcspn_test_1);
  tcase_add_test(tcase_core, s21_strcspn_test_2);
  tcase_add_test(tcase_core, s21_strcspn_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}