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
    int err_code = OK;
    int size;
    long double res = 0.0;
    long double term_1, term_2;
    if (!s21_is_valid_matrix(A) || !result) err_code = INCORRECT_MATRIX;
    else if (A->rows != A->columns) err_code = CALCULATION_ERROR;
    else size = A->rows;
    for (int i = 0; err_code == OK && i < size; i++){
        term_1 = term_2 = 1.0;
        for (int j = 0; err_code == OK && j < size; j++){
            term_1 *= A->matrix[j][(i + j) % size];
            term_2 *= A->matrix[j][(i - j) % size]; 
        }
        res += term_1 - term_2;
    }
    if (err_code == OK) {
        if (s21_is_valid_element((double)res)) *result = (double) res;
        else err_code = CALCULATION_ERROR;
    }
    return err_code;
}