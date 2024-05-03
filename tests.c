#include <check.h>
#include "quadratic_equation.h"

START_TEST(test_1) {
  double a = 0;
  double b = 0;
  double c = -3;

  Solution solution = solve_equation(a, b, c);
  ck_assert_double_nan(solution .x1);
  ck_assert_double_nan(solution .x2);
}
END_TEST

START_TEST(test_2) {
  double a = 0;
  double b = 2;
  double c = 2;

  Solution solution = solve_equation(a, b, c);
  ck_assert_double_eq(solution.x1, -1);
  ck_assert_double_eq(solution.x2, -1);
}
END_TEST

START_TEST(test_3) {
  double a = 1;
  double b = 5;
  double c = 4;

  Solution solution = solve_equation(a, b, c);
  ck_assert_double_eq(solution.x1, -1);
  ck_assert_double_eq(solution.x2, -4);
}
END_TEST

START_TEST(test_4) {
  double a = 1;
  double b = 2;
  double c = 1;

  Solution solution = solve_equation(a, b, c);
  ck_assert_double_eq(solution.x1, -1);
  ck_assert_double_eq(solution.x2, -1);
}
END_TEST

START_TEST(test_5) {
  double a = 2;
  double b = 2;
  double c = 1;

  Solution solution = solve_equation(a, b, c);
  ck_assert_double_nan(solution .x1);
  ck_assert_double_nan(solution .x2);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("testsCore");
  TCase *tCase = tcase_create("testsCore");
  SRunner *sRunner = srunner_create(suite);
  int testsFailed;

  suite_add_tcase(suite, tCase);
  tcase_add_test(tCase, test_1);
  tcase_add_test(tCase, test_2);
  tcase_add_test(tCase, test_3);
  tcase_add_test(tCase, test_4);
  tcase_add_test(tCase, test_5);

  srunner_run_all(sRunner, CK_ENV);
  testsFailed = srunner_ntests_failed(sRunner);
  srunner_free(sRunner);

  return  testsFailed == 0 ? 0 : 1;
}