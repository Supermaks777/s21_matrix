#include "../s21_matrix.h"
/**
 * @brief умножение матриц
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int err_code = OK;
    if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || !result) err_code = INCORRECT_MATRIX;
    else if (!s21_compatibility_size(*A, *B)) err_code = CALCULATION_ERROR;
    if (err_code == OK) {
        err_code = s21_create_matrix(A->rows,B->columns, result);
        for (int i = 0; i < A->rows && err_code == OK; i++){
            for (int j = 0; j < B->columns && err_code == OK; j++){
                double res = 0.0;
                for (int k = 0; k < B->rows; k++) res += A->matrix[i][k] * B->matrix[k][j];
                if (s21_is_valid_element(res)) result->matrix[i][j] = res;
                else err_code = CALCULATION_ERROR; 
            }
        }
    }
    return err_code;
}