#include "s21_test.h"

START_TEST(s21_mult_number_1) {
  // ошибка: null в указателе на результат
  matrix_t A = {};
  double number = 3.14;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_2) {
  // ошибка: умножение на бесконечное число
  matrix_t A = {};
  matrix_t result = {};
  double number = INFINITY;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_3) {
  // ошибка: бесконечность среди элементов матрицы
  matrix_t A = {};
  matrix_t result = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  A.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_4) {
  // успех: неинициализированная матрица
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_5) {
  // успех: инициализированная матрица
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_initialize_matrix(&eq_matrix, 3, 3);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_6) {
  // успех с заданными значениями
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *suite = suite_create("s21_mult_number");
  TCase *tc_core = tcase_create("core_of_mult_number");
  tcase_add_test(tc_core, s21_mult_number_1);
  tcase_add_test(tc_core, s21_mult_number_2);
  tcase_add_test(tc_core, s21_mult_number_3);
  tcase_add_test(tc_core, s21_mult_number_4);
  tcase_add_test(tc_core, s21_mult_number_5);
  tcase_add_test(tc_core, s21_mult_number_6);
  suite_add_tcase(suite, tc_core);

  return suite;
}