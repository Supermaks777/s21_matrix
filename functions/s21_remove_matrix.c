#include "../s21_matrix.h"
/**
 * @brief удаляет матрицу
 *
 * @param A матрица для удаления (matrix_t *)
 */
void s21_remove_matrix(matrix_t *A) {
  if (s21_is_valid_matrix_mini(A) == OK) {
    for (int i = 0; i < A->rows; i++)
      if (A->matrix[i]) {
        free(A->matrix[i]);
      }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}