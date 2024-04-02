#include "s21_sscanf_test.h"
#define EPS 1e-6

START_TEST(s21_sscanf_test_1) {
  short int result, res1;
  short int orig, orig1;
  char input[] = "4235554545445333443 56";
  s21_sscanf(input, "%hd %1hd", &result, &res1);
  sscanf(input, "%hd %1hd", &orig, &orig1);
  ck_assert_int_eq(result, orig);
  ck_assert_int_eq(res1, orig1);
}
END_TEST

START_TEST(s21_sscanf_test_2) {
  char str[20];
  char str1[20];
  char input[] = "Hello, world!";

  s21_sscanf(input, "%s", str);
  s21_sscanf(input, "%s", str1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sscanf_test_3) {
  unsigned short int ss, us, ss1, us1;
  char input[] = "AAAAAAAAAAAAAAA 55456789656787654";
  char format[1000] = "%hx %hu";

  s21_sscanf(input, format, &ss, &us);
  sscanf(input, format, &ss1, &us1);
  ck_assert_int_eq(ss, ss1);
  ck_assert_int_eq(us, us1);
}
END_TEST

START_TEST(s21_sscanf_test_4) {
  unsigned long int ss, us, ss1, us1;
  char input[] = "AAAAAAAAAAAAAAA 05545672656737654";
  char format[1000] = "%lx %lo";

  s21_sscanf(input, format, &ss, &us);
  sscanf(input, format, &ss1, &us1);
  ck_assert_int_eq(ss, ss1);
  ck_assert_int_eq(us, us1);
}
END_TEST

START_TEST(s21_sscanf_test_5) {
  unsigned int ss, us, ss1, us1;
  char input[] = "AAAAAAAAAAAAAAA 05545672656737654";
  char format[1000] = "%x %3o";

  s21_sscanf(input, format, &ss, &us);
  sscanf(input, format, &ss1, &us1);
  ck_assert_int_eq(ss, ss1);
  ck_assert_int_eq(us, us1);
}
END_TEST

// Multi test for %i
START_TEST(s21_sscanf_test_6) {
  int ss, us, a, b, c = 0;
  int ss1, us1, a1, b1, c1 = 0;
  char input[] = "-0xAAA 0554 444 0xA 055";
  char format[1000] = "%i %i %3i %2i %*i";

  s21_sscanf(input, format, &ss, &us, &a, &b, &c);
  sscanf(input, format, &ss1, &us1, &a1, &b1, &c1);

  ck_assert_int_eq(ss, ss1);
  ck_assert_int_eq(us, us1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
}
END_TEST

START_TEST(s21_sscanf_test_7) {
  long double d1, d1_s21;
  float d2, d2_s21;
  char input[] = "3.14 2.71";
  char format[1000] = "%Lf %f";

  s21_sscanf(input, format, &d1_s21, &d2_s21);
  sscanf(input, format, &d1, &d2);
  ck_assert_double_eq(d1_s21, d1);
  ck_assert_double_eq(d2_s21, d2);
}
END_TEST

START_TEST(s21_sscanf_test_8) {
  char str[20] = "", str1[20] = "", str2[20] = "";
  char input[] = "Hello, World!";
  char format[1000] = "%s %s %s";

  s21_sscanf(input, format, str, str1, str2);
  sscanf(input, format, str, str1, str2);
  ck_assert_str_eq(str, "Hello,");
  ck_assert_str_eq(str1, "World!");
  ck_assert_str_eq(str2, "");
}
END_TEST

START_TEST(s21_sscanf_test_9) {
  long int a, a_s21, c, c_s21;
  char input[] = "1056754356, 20, 305554355";
  char format[1000] = "%ld, %3ld";

  s21_sscanf(input, format, &a_s21, &c_s21);
  sscanf(input, format, &a, &c);
  ck_assert_int_eq(a_s21, a);
  ck_assert_int_eq(c_s21, c);
}
END_TEST

START_TEST(s21_sscanf_test_10) {
  char ch1 = 0, ch1_s21 = 0;
  char ch2 = 0, ch2_s21 = 0;
  char input[] = "a bdfdgf";
  char format[1000] = "%c %c";

  s21_sscanf(input, format, &ch1_s21, &ch2_s21);
  sscanf(input, format, &ch1, &ch2);
  ck_assert_int_eq(ch1_s21, ch1);
  ck_assert_int_eq(ch2_s21, ch2);
}
END_TEST

START_TEST(s21_sscanf_test_11) {
  int a = 0, b = 0;
  int a_s21 = 0, b_s21 = 0;
  char input[] = "123 456";
  char format[1000] = "%*d %3d";

  s21_sscanf(input, format, &a_s21, &b_s21);
  sscanf(input, format, &a, &b);
  ck_assert_int_eq(a_s21, a);
  ck_assert_int_eq(b_s21, b);
}
END_TEST

START_TEST(s21_sscanf_test_12) {
  unsigned int u1, u2;
  unsigned int u1_s21, u2_s21;
  char input[] = "123 456";
  char format[1000] = "%u %u";

  s21_sscanf(input, format, &u1_s21, &u2_s21);
  sscanf(input, format, &u1, &u2);
  ck_assert_int_eq(u1_s21, u1);
  ck_assert_int_eq(u2_s21, u2);
}
END_TEST

START_TEST(s21_sscanf_test_13) {
  long double f1, f1_s21;
  float f2, f2_s21;
  char input[] = "3.14534543543543534534534535 2e3";
  char format[1000] = "%Lf %e";

  s21_sscanf(input, format, &f1_s21, &f2_s21);
  sscanf(input, format, &f1, &f2);
  ck_assert_float_eq(f1_s21, f1);
  ck_assert_float_eq(f2_s21, f2);
}
END_TEST

START_TEST(s21_sscanf_test_14) {
  char format[] = "%f %G %LG %E";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  long double z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq_tol(q1, q2, EPS);
  ck_assert_ldouble_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(s21_sscanf_test_15) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_test_16) {
  float f1 = 0, f1_s21 = 0;
  float f2 = 0, f2_s21 = 0;
  char input[50] = "3E-2 1.55";
  char format[1000] = "%3g %3Lf";

  s21_sscanf(input, format, &f1_s21, &f2_s21);
  sscanf(input, format, &f1, &f2);
  ck_assert_float_eq(f1_s21, f1);
  ck_assert_double_eq(f2_s21, f2);
}
END_TEST

START_TEST(s21_sscanf_test_17) {
  short int a, a_s21;
  int b, b_s21;
  char input[] = "0xaa 20";
  char format[1000] = "%hi %X";

  s21_sscanf(input, format, &a_s21, &b_s21);
  sscanf(input, format, &a, &b);
  ck_assert_int_eq(a_s21, a);
  ck_assert_int_eq(b_s21, b);
}
END_TEST

START_TEST(s21_sscanf_test_19) {
  int percentage;
  int percentage_s21;
  char input[] = "42%";
  char format[1000] = "%d%%";

  s21_sscanf(input, format, &percentage_s21);
  sscanf(input, format, &percentage);
  ck_assert_int_eq(percentage_s21, percentage);
}
END_TEST

START_TEST(s21_sscanf_test_20) {
  wchar_t ch2 = 0, ch2_s21 = 0;
  char input[] = "bdfdgf";
  char format[1000] = "%lc";

  s21_sscanf(input, format, &ch2_s21);
  sscanf(input, format, &ch2);
  ck_assert_int_eq(ch2_s21, ch2);
}
END_TEST

START_TEST(s21_sscanf_test_21) {
  long int a, a_s21;
  short int b, b_s21, c, c_s21;
  char input[] = "0xAA 076 99";
  char format[1000] = "%li %hi %hi";

  s21_sscanf(input, format, &a_s21, &b_s21, &c_s21);
  sscanf(input, format, &a, &b, &c);
  ck_assert_int_eq(a_s21, a);
  ck_assert_int_eq(b_s21, b);
  ck_assert_int_eq(c_s21, c);
}
END_TEST

START_TEST(s21_sscanf_test_22) {
  long int a, a_s21;
  long int b, b_s21;
  char input[] = "076 99";
  char format[1000] = "%li %li";

  s21_sscanf(input, format, &a_s21, &b_s21);
  sscanf(input, format, &a, &b);
  ck_assert_int_eq(a_s21, a);
  ck_assert_int_eq(b_s21, b);
}
END_TEST

START_TEST(s21_sscanf_test_23) {
  char s[20] = "";
  char s_21[20] = "";
  char input[] = "";
  char format[1000] = "%s";

  s21_sscanf(input, format, &s_21);
  sscanf(input, format, &s);
  ck_assert_str_eq(s, s_21);
}
END_TEST

START_TEST(s21_sscanf_test_24) {
  char a = '\0';
  char a_s21 = '\0';
  char format[1000] = "%c";

  s21_sscanf("\0", format, &a_s21);
  sscanf("\0", format, &a);
  ck_assert_int_eq(a_s21, a);
}
END_TEST

START_TEST(s21_sscanf_test_25) {
  char format[] = "%p";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_26) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(s21_sscanf_test_27) {
  char format[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(s21_sscanf_test_28) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(s21_sscanf_test_29) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(s21_sscanf_test_30) {
  char format[] = "%n";
  char str[] = "IlyaTester";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_sscanf_test_31) {
  int result;
  char input[] = "123 ABC";
  char format[1000] = "%d %Y";

  int value1 = 0, value2 = 0;
  result = s21_sscanf(input, format, &value1, &value2);

  ck_assert_int_eq(result, 1);

  ck_assert_int_eq(value1, 123);

  ck_assert_int_eq(value2, 0);
}
END_TEST

START_TEST(s21_sscanf_test_32) {
  char format[] = "%ln %Ln";
  char str[] = "12345 67890";
  long int ln_val_s21;
  long int Ln_val_s21;

  long int ln_val;
  long int Ln_val;

  int16_t res1 = s21_sscanf(str, format, &ln_val_s21, &Ln_val_s21);
  int16_t res2 = sscanf(str, format, &ln_val, &Ln_val);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(ln_val_s21, ln_val);
  ck_assert_int_eq(Ln_val_s21, Ln_val);
}
END_TEST

// Add more tests as needed...

Suite *s21_sscanf_suite_create(void) {
  Suite *suite = suite_create("s21_sscanf_suite");
  TCase *tcase_core = tcase_create("s21_sscanf_tcase");

  tcase_add_test(tcase_core, s21_sscanf_test_1);
  tcase_add_test(tcase_core, s21_sscanf_test_2);
  tcase_add_test(tcase_core, s21_sscanf_test_3);
  tcase_add_test(tcase_core, s21_sscanf_test_4);
  tcase_add_test(tcase_core, s21_sscanf_test_5);
  tcase_add_test(tcase_core, s21_sscanf_test_6);
  tcase_add_test(tcase_core, s21_sscanf_test_7);
  tcase_add_test(tcase_core, s21_sscanf_test_8);
  tcase_add_test(tcase_core, s21_sscanf_test_9);
  tcase_add_test(tcase_core, s21_sscanf_test_10);
  tcase_add_test(tcase_core, s21_sscanf_test_11);
  tcase_add_test(tcase_core, s21_sscanf_test_12);
  tcase_add_test(tcase_core, s21_sscanf_test_13);
  tcase_add_test(tcase_core, s21_sscanf_test_14);
  tcase_add_test(tcase_core, s21_sscanf_test_15);
  tcase_add_test(tcase_core, s21_sscanf_test_16);
  tcase_add_test(tcase_core, s21_sscanf_test_17);
  tcase_add_test(tcase_core, s21_sscanf_test_19);
  tcase_add_test(tcase_core, s21_sscanf_test_20);
  tcase_add_test(tcase_core, s21_sscanf_test_21);
  tcase_add_test(tcase_core, s21_sscanf_test_22);
  tcase_add_test(tcase_core, s21_sscanf_test_23);
  tcase_add_test(tcase_core, s21_sscanf_test_24);
  tcase_add_test(tcase_core, s21_sscanf_test_25);
  tcase_add_test(tcase_core, s21_sscanf_test_26);
  tcase_add_test(tcase_core, s21_sscanf_test_27);
  tcase_add_test(tcase_core, s21_sscanf_test_28);
  tcase_add_test(tcase_core, s21_sscanf_test_29);
  tcase_add_test(tcase_core, s21_sscanf_test_30);
  tcase_add_test(tcase_core, s21_sscanf_test_31);
  tcase_add_test(tcase_core, s21_sscanf_test_32);

  // Add more tests...

  suite_add_tcase(suite, tcase_core);

  return suite;
}