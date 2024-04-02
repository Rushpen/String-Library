#include "s21_memchr_test.h"

START_TEST(s21_memchr_test_1) {
  const char* haystack = "Hello, world!";
  char needle = 'o';
  s21_size_t size = 13;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, size),
                   memchr(haystack, needle, size));
}
END_TEST

START_TEST(s21_memchr_test_2) {
  const char* haystack = "abcde";
  char needle = 'z';
  s21_size_t size = 5;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, size),
                   memchr(haystack, needle, size));
}
END_TEST

START_TEST(s21_memchr_test_3) {
  const char* haystack = "Hello, world!";
  char needle = '!';
  s21_size_t size = 13;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, size),
                   memchr(haystack, needle, size));
}
END_TEST

START_TEST(s21_memchr_test_4) {
  const char* haystack = "abcde";
  char needle = 'a';
  s21_size_t size = 2;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, size),
                   memchr(haystack, needle, size));
}
END_TEST

Suite* s21_memchr_suite_create(void) {
  Suite* suite = suite_create("s21_memchr_suite");
  TCase* tcase_core = tcase_create("s21_memchr_tcase");

  tcase_add_test(tcase_core, s21_memchr_test_1);
  tcase_add_test(tcase_core, s21_memchr_test_2);
  tcase_add_test(tcase_core, s21_memchr_test_3);
  tcase_add_test(tcase_core, s21_memchr_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
