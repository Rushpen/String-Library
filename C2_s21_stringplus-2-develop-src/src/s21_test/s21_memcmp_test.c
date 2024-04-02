#include "s21_memcmp_test.h"

START_TEST(s21_memcmp_test_1) {
  const char* str1 = "abc";
  const char* str2 = "abc";
  s21_size_t size = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, size), 0);
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  const char* str1 = "ayz";
  const char* str2 = "abc";
  s21_size_t size = 3;

  ck_assert_int_gt(s21_memcmp(str1, str2, size),
                   0);  // Проверяем, что результат отрицателен
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  const char* str1 = "abc";
  const char* str2 = "abcd";
  s21_size_t size = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, size), memcmp(str1, str2, size));
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  const char* str1 = "xyz";
  const char* str2 = "xyz";
  s21_size_t size = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, size), 0);
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  const char* str1 = "abc";
  const char* str2 = "abd";
  s21_size_t size = 3;

  ck_assert_int_lt(s21_memcmp(str1, str2, size), 0);
}
END_TEST

START_TEST(s21_memcmp_test_6) {
  const char* str1 = "abcd";
  const char* str2 = "abc";
  s21_size_t size = 4;

  ck_assert_int_gt(s21_memcmp(str1, str2, size),
                   0);  // Проверяем, что результат положителен
}
END_TEST

START_TEST(s21_memcmp_test_7) {
  const char* str1 = "bcd";
  const char* str2 = "abc";
  s21_size_t size = 3;

  ck_assert_int_gt(s21_memcmp(str1, str2, size), 0);
}
END_TEST

Suite* s21_memcmp_suite_create(void) {
  Suite* suite = suite_create("s21_memcmp_suite");
  TCase* tcase_core = tcase_create("s21_memcmp_tcase");

  tcase_add_test(tcase_core, s21_memcmp_test_1);
  tcase_add_test(tcase_core, s21_memcmp_test_2);
  tcase_add_test(tcase_core, s21_memcmp_test_3);
  tcase_add_test(tcase_core, s21_memcmp_test_4);
  tcase_add_test(tcase_core, s21_memcmp_test_5);
  tcase_add_test(tcase_core, s21_memcmp_test_6);
  tcase_add_test(tcase_core, s21_memcmp_test_7);

  suite_add_tcase(suite, tcase_core);

  return suite;
}