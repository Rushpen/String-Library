#include "s21_sprintf_test.h"

START_TEST(s21_sprintf_test_1) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%8s %9s", "Hello,", "world!");
  sprintf(buffer1, "%8s %9s", "Hello,", "world!");

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_2) {
  char buffer[50] = "";
  char buffer1[50] = "";
  long int a = 42;
  s21_sprintf(buffer, "%ld %s", a, "apples");
  sprintf(buffer1, "%ld %s", a, "apples");

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_3) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%c%c%c", 'a', 'b', 'c');
  sprintf(buffer1, "%c%c%c", 'a', 'b', 'c');

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_4) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%f", 3.14);
  sprintf(buffer1, "%f", 3.14);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_5) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "The answer is %-d", 42);
  sprintf(buffer1, "The answer is %-d", 42);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_6) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%c%c", 'a', '\0');
  sprintf(buffer1, "%c%c", 'a', '\0');

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_7) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%x", 55);
  sprintf(buffer1, "%x", 55);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_8) {
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%.2f", 7.777);
  sprintf(buffer1, "%.2f", 7.777);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_9) {
  void* ptr = (void*)0x12345678;
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%p", ptr);
  sprintf(buffer1, "%p", ptr);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_10) {
  double num = -123.456;
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%+10.3f", num);
  sprintf(buffer1, "%+10.3f", num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_11) {
  double num = 12345.6789;
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%.1g", num);
  sprintf(buffer1, "%.1g", num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_12) {
  double num = 0.000012345;
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%*.*f", 7, 3, num);
  sprintf(buffer1, "%*.*f", 7, 3, num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_13) {
  double num = 987654.2321;
  double num1 = 987654.2321;
  char buffer[50] = "";
  char buffer1[50] = "";
  s21_sprintf(buffer, "%G", num);
  sprintf(buffer1, "%G", num1);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_14) {
  short unsigned int hex_num = 0xAAAA;
  unsigned int H = 0xBBB5;
  char buffer_lower[50] = "";
  char buffer_upper[50] = "";
  char buffer_lower1[50] = "";
  char buffer_upper1[50] = "";

  s21_sprintf(buffer_lower, "%hx", (unsigned short)hex_num);
  sprintf(buffer_lower1, "%hx", (unsigned short)hex_num);

  s21_sprintf(buffer_upper, "%X", H);
  sprintf(buffer_upper1, "%X", H);

  ck_assert_str_eq(buffer_upper, buffer_upper1);
  ck_assert_str_eq(buffer_lower, buffer_lower1);
}
END_TEST

START_TEST(s21_sprintf_test_15) {
  unsigned int hex_num = 0x1A3;
  double scientific_num = 1.23e4;

  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Hex: %X, Scientific: %e", hex_num, scientific_num);
  sprintf(buffer1, "Hex: %X, Scientific: %e", hex_num, scientific_num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_16) {
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Name: %s, Age: %d, GPA: %.2f, ID: %08X", "John Doe", 25,
              3.75, 12345678);
  sprintf(buffer1, "Name: %s, Age: %d, GPA: %.2f, ID: %08X", "John Doe", 25,
          3.75, 12345678);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_17) {
  int num = 42;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %d, Padded: %5d", num, num);
  sprintf(buffer1, "Original: %d, Padded: %5d", num, num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_18) {
  int num = 42;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %d, Padded with zeros: %05d", num, num);
  sprintf(buffer1, "Original: %d, Padded with zeros: %05d", num, num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_19) {
  int num = 42;
  int num1 = 42;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "% d", num);
  sprintf(buffer1, "% d", num1);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_20) {
  int num = 042;
  int num1 = 042;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %o", num);
  sprintf(buffer1, "Original: %o", num1);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_21) {
  unsigned int num = 42;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %u", num);
  sprintf(buffer1, "Original: %u", num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_22) {
  double num = 3.14;
  long double num1 = 3.14;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "%e, With L flag: %Lg", num, num1);
  sprintf(buffer1, "%e, With L flag: %Lg", num, num1);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_23) {
  double num = 3.14;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %f, With E flag: %E", num, num);
  sprintf(buffer1, "Original: %f, With E flag: %E", num, num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_24) {
  double num = 3.14;
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Original: %g, With L flag: %G", num, num);
  sprintf(buffer1, "Original: %g, With L flag: %G", num, num);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_25) {
  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Percentage: %%");
  sprintf(buffer1, "Percentage: %%");

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s21_sprintf_test_26) {
  double scientific_num = 1.23e4;

  char buffer[50] = "";
  char buffer1[50] = "";

  s21_sprintf(buffer, "Scientific: %#e", scientific_num);
  sprintf(buffer1, "Scientific: %#e", scientific_num);

  ck_assert_str_eq(buffer, buffer1);
}

START_TEST(s21_sprintf_test_27) {
  char str1[1000] = "11111111     11";
  char str2[1000] = "%3s %s %%";

  s21_sprintf(str1, str2, "qqqqqqqq", NULL);

  char str3[1000] = "11111111     11";
  char str4[1000] = "%3s %s %%";
  sprintf(str3, str4, "qqqqqqqq", NULL);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_28) {
  char str1[1000] = "11111111     11";
  char str2[1000] = "%3s %10p %%";

  s21_sprintf(str1, str2, "qqqqqqqq", NULL);

  char str3[1000] = "11111111     11";
  char str4[1000] = "%3s %10p %%";
  sprintf(str3, str4, "qqqqqqqq", NULL);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_29) {
  char str1[1000] = "11111111     11";
  char str2[1000] = "%2c %5c %%";

  s21_sprintf(str1, str2, "qqqqqqqq", NULL);

  char str3[1000] = "11111111     11";
  char str4[1000] = "%2c %5c %%";
  sprintf(str3, str4, "qqqqqqqq", NULL);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_30) {
  char str1[1000] = "11111111     11";
  char str2[1000] = "%010d";

  s21_sprintf(str1, str2, 123);

  char str3[1000] = "11111111";
  char str4[1000] = "%010d";
  sprintf(str3, str4, 123);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_31) {
  char str1[1000] = "";
  char str2[1000] = "%-015.3f";

  s21_sprintf(str1, str2, 123.456);

  char str3[1000] = "";
  char str4[1000] = "%-015.3f";
  sprintf(str3, str4, 123.456);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_32) {
  char str1[1000] = "";
  char str2[1000] = "%#g";

  s21_sprintf(str1, str2, 3.0);

  char str3[1000] = "";
  char str4[1000] = "%#g";
  sprintf(str3, str4, 3.0);

  ck_assert_str_eq(str1, str3);
}

START_TEST(s21_sprintf_test_33) {
  char str1[1000] = "";
  char str2[1000] = "%.3G";

  s21_sprintf(str1, str2, 12.666);

  char str3[1000] = "";
  char str4[1000] = "%.3G";
  sprintf(str3, str4, 12.666);

  ck_assert_str_eq(str1, str3);
}

Suite* s21_sprintf_suite_create(void) {
  Suite* suite = suite_create("s21_sprintf_suite");
  TCase* tcase_core = tcase_create("s21_sprintf_tcase");

  tcase_add_test(tcase_core, s21_sprintf_test_1);
  tcase_add_test(tcase_core, s21_sprintf_test_2);
  tcase_add_test(tcase_core, s21_sprintf_test_3);
  tcase_add_test(tcase_core, s21_sprintf_test_4);
  tcase_add_test(tcase_core, s21_sprintf_test_5);
  tcase_add_test(tcase_core, s21_sprintf_test_6);
  tcase_add_test(tcase_core, s21_sprintf_test_7);
  tcase_add_test(tcase_core, s21_sprintf_test_8);
  tcase_add_test(tcase_core, s21_sprintf_test_9);
  tcase_add_test(tcase_core, s21_sprintf_test_10);
  tcase_add_test(tcase_core, s21_sprintf_test_11);
  tcase_add_test(tcase_core, s21_sprintf_test_12);
  tcase_add_test(tcase_core, s21_sprintf_test_13);
  tcase_add_test(tcase_core, s21_sprintf_test_14);
  tcase_add_test(tcase_core, s21_sprintf_test_15);
  tcase_add_test(tcase_core, s21_sprintf_test_16);
  tcase_add_test(tcase_core, s21_sprintf_test_17);
  tcase_add_test(tcase_core, s21_sprintf_test_18);
  tcase_add_test(tcase_core, s21_sprintf_test_19);
  tcase_add_test(tcase_core, s21_sprintf_test_20);
  tcase_add_test(tcase_core, s21_sprintf_test_21);
  tcase_add_test(tcase_core, s21_sprintf_test_22);
  tcase_add_test(tcase_core, s21_sprintf_test_23);
  tcase_add_test(tcase_core, s21_sprintf_test_24);
  tcase_add_test(tcase_core, s21_sprintf_test_25);
  tcase_add_test(tcase_core, s21_sprintf_test_26);
  tcase_add_test(tcase_core, s21_sprintf_test_27);
  tcase_add_test(tcase_core, s21_sprintf_test_28);
  tcase_add_test(tcase_core, s21_sprintf_test_29);
  tcase_add_test(tcase_core, s21_sprintf_test_30);
  tcase_add_test(tcase_core, s21_sprintf_test_31);
  tcase_add_test(tcase_core, s21_sprintf_test_32);
  tcase_add_test(tcase_core, s21_sprintf_test_33);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
