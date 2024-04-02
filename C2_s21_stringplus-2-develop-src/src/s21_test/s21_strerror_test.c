#include "s21_strerror_test.h"

START_TEST(s21_strerror_test_1) {
  int errnum = EDOM;  // Ошибка домена
  const char *expected = strerror(errnum);
  const char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_strerror_test_2) {
  int errnum = EINVAL;  // Недопустимый аргумент
  const char *expected = strerror(errnum);
  const char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_strerror_test_3) {
  int errnum = EACCES;  // Ошибка доступа
  const char *expected = strerror(errnum);
  const char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(s21_strerror_test_4) {
  int errnum = 134;  // Неизвестная ошибка
  const char *expected = strerror(errnum);
  const char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *s21_strerror_suite_create(void) {
  Suite *suite = suite_create("s21_strerror_suite");
  TCase *tcase_core = tcase_create("s21_strerror_tcase");

  tcase_add_test(tcase_core, s21_strerror_test_1);
  tcase_add_test(tcase_core, s21_strerror_test_2);
  tcase_add_test(tcase_core, s21_strerror_test_3);
  tcase_add_test(tcase_core, s21_strerror_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}