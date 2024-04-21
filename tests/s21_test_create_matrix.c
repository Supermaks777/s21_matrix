#include "s21_test.h"

START_TEST(s21_create_matrix_1) {
  // успешное создание
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  // ошибка: пустой указатель на результат
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  // ошибка: некорректное количество столбцов
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  // ошибка: некорректное количество строк
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 5, &A), INCORRECT_MATRIX);
}
END_TEST


Suite *s21_create_matrix_suite(void) {
  Suite *suite = suite_create("s21_create_matrix");
  TCase *tc_core = tcase_create("core_of_create_matrix");
  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  suite_add_tcase(suite, tc_core);

  return suite;
}