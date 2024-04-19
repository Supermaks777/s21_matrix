#include "s21_matrix.h"
/**
 * @brief инвертирует матрицу
 * 
 * @param A первая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int err_code = OK;
    double determinant = 0;
    if (!s21_is_valid_matrix(A) || !result) err_code = INCORRECT_MATRIX;
    else if (A->rows != A->columns) err_code = CALCULATION_ERROR;
    else if (!s21_determinant(A, &determinant)) err_code = CALCULATION_ERROR;

    if (err_code == OK && A->rows == 1) {
        if (s21_create_matrix(1, 1, result) == OK) result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
        matrix_t temp_algebraic_complements = {0};
        matrix_t transposed_temp_algebraic_complements = {0};
        err_code = s21_calc_complements(A, &temp_algebraic_complements);
        if (err_code == OK) err_code = s21_transpose(&temp_algebraic_complements, &transposed_temp_algebraic_complements);
        if (err_code == OK) err_code = s21_mult_number(&transposed_temp_algebraic_complements, 1 / determinant, result);
        s21_remove_matrix(&temp_algebraic_complements);
        s21_remove_matrix(&transposed_temp_algebraic_complements);
    }
    return err_code;
}