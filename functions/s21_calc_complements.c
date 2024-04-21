#include "../s21_matrix.h"

/**
 * @brief формирует матрицу алгебраических дополнений
 * 
 * @param A исходная матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int err_code = OK;
    int element_sign;
    double element_value;
    if (!s21_is_valid_matrix(A)) err_code = INCORRECT_MATRIX;
    else if (!result) err_code = INCORRECT_MATRIX;
    else if (A->rows != A->columns) err_code = CALCULATION_ERROR;
    if (err_code == OK) err_code = s21_create_matrix(A->rows,A->columns, result);
    if (err_code == OK && A->rows == 2) {
        result->matrix[0][0] = A->matrix[1][1];
        result->matrix[0][1] = -A->matrix[1][0];
        result->matrix[1][0] = -A->matrix[0][1];
        result->matrix[1][1] = A->matrix[0][0];
    } else if (err_code == OK){
        for (int i = 0; i < A->rows && err_code == OK; i++){
            for (int j = 0; j < A->columns && err_code == OK; j++){
                element_value = s21_get_minor(A, i, j, &err_code);
                element_sign = pow(-1, i + j);
                result->matrix[i][j] = element_sign * element_value;
            }
        }
    }
    return err_code;
}
