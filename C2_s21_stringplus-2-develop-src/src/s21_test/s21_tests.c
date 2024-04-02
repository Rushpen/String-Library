#include <check.h>

#include "s21_insert_test.h"
#include "s21_memchr_test.h"
#include "s21_memcmp_test.h"
#include "s21_memcpy_test.h"
#include "s21_memset_test.h"
#include "s21_sprintf_test.h"
#include "s21_sscanf_test.h"
#include "s21_strchr_test.h"
#include "s21_strcspn_test.h"
#include "s21_strerror_test.h"
#include "s21_strlen_test.h"
#include "s21_strncat_test.h"
#include "s21_strncmp_test.h"
#include "s21_strncpy_test.h"
#include "s21_strpbrk_test.h"
#include "s21_strrchr_test.h"
#include "s21_strstr_test.h"
#include "s21_strtok_test.h"
#include "s21_to_lower_test.h"
#include "s21_to_upper_test.h"
#include "s21_trim_test.h"

int main() {
  int failed_count = 0;
  Suite* suite1 = s21_memcpy_suite_create();
  Suite* suite2 = s21_memset_suite_create();
  Suite* suite3 = s21_sprintf_suite_create();
  Suite* suite4 = s21_sscanf_suite_create();
  Suite* suite5 = s21_strchr_suite_create();
  Suite* suite6 = s21_strcspn_suite_create();
  Suite* suite7 = s21_strerror_suite_create();
  Suite* suite8 = s21_strlen_suite_create();
  Suite* suite9 = s21_strncat_suite_create();
  Suite* suite10 = s21_strncmp_suite_create();
  Suite* suite11 = s21_strncpy_suite_create();
  Suite* suite12 = s21_strpbrk_suite_create();
  Suite* suite13 = s21_strrchr_suite_create();
  Suite* suite14 = s21_strstr_suite_create();
  Suite* suite15 = s21_strtok_suite_create();
  Suite* suite16 = s21_to_lower_suite_create();
  Suite* suite17 = s21_to_upper_suite_create();
  Suite* suite18 = s21_trim_suite_create();
  Suite* suite19 = s21_insert_suite_create();
  Suite* suite20 = s21_memchr_suite_create();
  Suite* suite21 = s21_memcmp_suite_create();

  SRunner* suite_runner1 = srunner_create(suite1);
  SRunner* suite_runner2 = srunner_create(suite2);
  SRunner* suite_runner3 = srunner_create(suite3);
  SRunner* suite_runner4 = srunner_create(suite4);
  SRunner* suite_runner5 = srunner_create(suite5);
  SRunner* suite_runner6 = srunner_create(suite6);
  SRunner* suite_runner7 = srunner_create(suite7);
  SRunner* suite_runner8 = srunner_create(suite8);
  SRunner* suite_runner9 = srunner_create(suite9);
  SRunner* suite_runner10 = srunner_create(suite10);
  SRunner* suite_runner11 = srunner_create(suite11);
  SRunner* suite_runner12 = srunner_create(suite12);
  SRunner* suite_runner13 = srunner_create(suite13);
  SRunner* suite_runner14 = srunner_create(suite14);
  SRunner* suite_runner15 = srunner_create(suite15);
  SRunner* suite_runner16 = srunner_create(suite16);
  SRunner* suite_runner17 = srunner_create(suite17);
  SRunner* suite_runner18 = srunner_create(suite18);
  SRunner* suite_runner19 = srunner_create(suite19);
  SRunner* suite_runner20 = srunner_create(suite20);
  SRunner* suite_runner21 = srunner_create(suite21);

  srunner_run_all(suite_runner1, CK_NORMAL);
  srunner_run_all(suite_runner2, CK_NORMAL);
  srunner_run_all(suite_runner3, CK_NORMAL);
  srunner_run_all(suite_runner4, CK_NORMAL);
  srunner_run_all(suite_runner5, CK_NORMAL);
  srunner_run_all(suite_runner6, CK_NORMAL);
  srunner_run_all(suite_runner7, CK_NORMAL);
  srunner_run_all(suite_runner8, CK_NORMAL);
  srunner_run_all(suite_runner9, CK_NORMAL);
  srunner_run_all(suite_runner10, CK_NORMAL);
  srunner_run_all(suite_runner11, CK_NORMAL);
  srunner_run_all(suite_runner12, CK_NORMAL);
  srunner_run_all(suite_runner13, CK_NORMAL);
  srunner_run_all(suite_runner14, CK_NORMAL);
  srunner_run_all(suite_runner15, CK_NORMAL);
  srunner_run_all(suite_runner16, CK_NORMAL);
  srunner_run_all(suite_runner17, CK_NORMAL);
  srunner_run_all(suite_runner18, CK_NORMAL);
  srunner_run_all(suite_runner19, CK_NORMAL);
  srunner_run_all(suite_runner20, CK_NORMAL);
  srunner_run_all(suite_runner21, CK_NORMAL);

  failed_count += srunner_ntests_failed(suite_runner1);
  failed_count += srunner_ntests_failed(suite_runner2);
  failed_count += srunner_ntests_failed(suite_runner3);
  failed_count += srunner_ntests_failed(suite_runner4);
  failed_count += srunner_ntests_failed(suite_runner5);
  failed_count += srunner_ntests_failed(suite_runner6);
  failed_count += srunner_ntests_failed(suite_runner7);
  failed_count += srunner_ntests_failed(suite_runner8);
  failed_count += srunner_ntests_failed(suite_runner9);
  failed_count += srunner_ntests_failed(suite_runner10);
  failed_count += srunner_ntests_failed(suite_runner11);
  failed_count += srunner_ntests_failed(suite_runner12);
  failed_count += srunner_ntests_failed(suite_runner13);
  failed_count += srunner_ntests_failed(suite_runner14);
  failed_count += srunner_ntests_failed(suite_runner15);
  failed_count += srunner_ntests_failed(suite_runner16);
  failed_count += srunner_ntests_failed(suite_runner17);
  failed_count += srunner_ntests_failed(suite_runner18);
  failed_count += srunner_ntests_failed(suite_runner19);
  failed_count += srunner_ntests_failed(suite_runner20);
  failed_count += srunner_ntests_failed(suite_runner21);

  srunner_free(suite_runner1);
  srunner_free(suite_runner2);
  srunner_free(suite_runner3);
  srunner_free(suite_runner4);
  srunner_free(suite_runner5);
  srunner_free(suite_runner6);
  srunner_free(suite_runner7);
  srunner_free(suite_runner8);
  srunner_free(suite_runner9);
  srunner_free(suite_runner10);
  srunner_free(suite_runner11);
  srunner_free(suite_runner12);
  srunner_free(suite_runner13);
  srunner_free(suite_runner14);
  srunner_free(suite_runner15);
  srunner_free(suite_runner16);
  srunner_free(suite_runner17);
  srunner_free(suite_runner18);
  srunner_free(suite_runner19);
  srunner_free(suite_runner20);
  srunner_free(suite_runner21);

  printf("Fail = %d\n", failed_count);

  return 0;
}