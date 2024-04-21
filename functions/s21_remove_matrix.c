#include "../s21_matrix.h"
/**
 * @brief удаляет матрицу
 *
 * @param A матрица для удаления
 */
void s21_remove_matrix(matrix_t *A) {
    // printf("%d\n", A && A->matrix);
    if (A && A->matrix) {
        for (int i = 0; i < A->rows; i++) if (A->matrix[i]) free(A->matrix[i]);
        free(A->matrix);
        A->matrix = NULL;
    }
}