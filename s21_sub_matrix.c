#include "s21_matrix.h"
/**
 * @brief вычитает матрицы
 * 
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int err_code = OK;
    double sum = 0.0;
    if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B)) err_code = INCORRECT_MATRIX;
    else if (!s21_eq_size(*A, *B)) err_code = CALCULATION_ERROR;
    err_code = s21_create_matrix(A->rows,A->columns, result);
    if (err_code == OK) {
        for (int i = 0; i < A->rows && err_code == OK; i++){
            for (int j = 0; j < A->columns && err_code == OK; j++){
                sum = A->matrix[i][j] - B->matrix[i][j];
                if (s21_is_valid_element(sum)) result->matrix[i][j] = sum;
                else err_code = CALCULATION_ERROR; 
            }
        }
    }
    return err_code;
}