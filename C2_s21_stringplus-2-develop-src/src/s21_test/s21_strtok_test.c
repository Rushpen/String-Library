#include "s21_strtok_test.h"

START_TEST(s21_strtok_test_1) {
  char str[] = "Hello, world! How are you?";
  const char delim[] = " ,!?";

  char *expected_token = strtok(str, delim);
  char *expected_remainder = str;

  char *result_token = s21_strtok(str, delim);
  char *result_remainder = str;

  ck_assert_str_eq(result_token, expected_token);
  ck_assert_str_eq(result_remainder, expected_remainder);
}
END_TEST

START_TEST(s21_strtok_test_2) {
  char str[] = "One,Two,,Three";
  const char delim[] = ",";

  char *expected_token = strtok(str, delim);
  char *expected_remainder = str;

  char *result_token = s21_strtok(str, delim);
  char *result_remainder = str;

  ck_assert_str_eq(result_token, expected_token);
  ck_assert_str_eq(result_remainder, expected_remainder);
}
END_TEST

START_TEST(s21_strtok_test_3) {
  char str[] = "This,is a test";
  const char delim[] = " ";

  char *expected_token = strtok(str, delim);
  char *expected_remainder = str;

  char *result_token = s21_strtok(str, delim);
  char *result_remainder = str;

  ck_assert_str_eq(result_token, expected_token);
  ck_assert_str_eq(result_remainder, expected_remainder);
}
END_TEST

START_TEST(s21_strtok_test_4) {
  char str[] = " Delimiter at the start";
  const char delim[] = " ";

  char *expected_token = strtok(str, delim);
  char *expected_remainder = str;

  char *result_token = s21_strtok(str, delim);
  char *result_remainder = str;

  ck_assert_str_eq(result_token, expected_token);
  ck_assert_str_eq(result_remainder, expected_remainder);
}
END_TEST

START_TEST(s21_strtok_test_5) {
  char str[] = "Back up";
  const char delim[] = " ";

  char *backup_str = s21_strtok(str, delim);
  char *expected_token = backup_str;
  char *expected_remainder = backup_str + 1;

  char *result_token = s21_strtok(str, delim);
  char *result_remainder = backup_str + 1;

  ck_assert_str_eq(result_token, expected_token);
  ck_assert_str_eq(result_remainder, expected_remainder);
}
END_TEST

Suite *s21_strtok_suite_create(void) {
  Suite *suite = suite_create("s21_strtok_suite");
  TCase *tcase_core = tcase_create("s21_strtok_tcase");

  tcase_add_test(tcase_core, s21_strtok_test_1);
  tcase_add_test(tcase_core, s21_strtok_test_2);
  tcase_add_test(tcase_core, s21_strtok_test_3);
  tcase_add_test(tcase_core, s21_strtok_test_4);
  tcase_add_test(tcase_core, s21_strtok_test_5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}