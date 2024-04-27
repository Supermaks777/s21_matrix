#include "../s21_matrix.h"
/**
 * @brief расчитывает определитель квадратной матрицы
 *
 * @param A исходная матрица (matrix_t)
 * @param result результат (double)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_determinant(matrix_t *A, double *result) {
  long double res = 0.0;
  long double term_1, term_2;
  int err_code = OK;
  if (err_code == OK) err_code = s21_is_valid_matrix_full(A);
  if (err_code == OK) err_code = s21_squar_size(A);
  if (err_code == OK) {
    if (A->rows == 1)
      res = A->matrix[0][0];
    else if (A->rows == 2)
      res =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    else
      for (int i = 0; err_code == OK && i < A->rows; i++) {
        term_1 = 1.0;
        term_2 = 1.0;
        for (int j = 0; err_code == OK && j < A->rows; j++) {
          term_1 *= A->matrix[j][s21_correct_index(i + j, A->rows)];
          term_2 *= A->matrix[j][s21_correct_index(i - j, A->rows)];
        }
        res += term_1 - term_2;
      }
  }
  if (err_code == OK) err_code = s21_is_valid_element((double)res);
  if (err_code == OK) *result = (double)res;
  return err_code;
}