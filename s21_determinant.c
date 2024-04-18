#include "s21_matrix.h"
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
    long double res = 0.0;
    long double term_1, term_2;
    if (!s21_is_valid_matrix(A) || !result) err_code = INCORRECT_MATRIX;
    if (A->rows != A->columns) err_code= CALCULATION_ERROR;
    int size = A->rows;
    for (int i = 0; i < size && err_code == OK; i++){
        term_1 = term_2 = 1.0;
        for (int j = 0; j < size && err_code == OK; j++){
            term_1 *= A->matrix[j][(i + j) % size];
            term_2 *= A->matrix[j][(i - j) % size]; 
        }
        res += term_1 - term_2;
    }
    if (s21_is_valid_element((double)res)) *result = (double) res;
    else err_code = CALCULATION_ERROR;
}