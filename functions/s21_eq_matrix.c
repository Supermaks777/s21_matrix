#include "../s21_matrix.h"

/**
 * @brief сравнивает две матрицы
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результат (double)
 * @return результат сравнения (int)
 * @retval 0 - FAILURE.
 * @retval 1 - SUCCESS.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  printf("s21_eq_matrix.check_1: %d\n", s21_is_valid_matrix_full(A));
  printf("s21_eq_matrix.check_2: %d\n", s21_is_valid_matrix_full(B));
  printf("s21_eq_matrix.check_3: %d\n", s21_eq_size(A, B));
  printf("s21_eq_matrix.check_4: %d\n", !s21_eq_content(A, B));
  printf("s21_eq_matrix.check_total: %d\n", s21_is_valid_matrix_full(A) || s21_is_valid_matrix_full(B) ||
          s21_eq_size(A, B) || !s21_eq_content(A, B));
  return (s21_is_valid_matrix_full(A) || s21_is_valid_matrix_full(B) ||
          s21_eq_size(A, B) || !s21_eq_content(A, B))
             ? FAILURE
             : SUCCESS;
}
