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
    s21_print_matrix(A);
    if (!s21_is_valid_matrix(A) || !result) err_code = INCORRECT_MATRIX;
    else if (A->rows != A->columns) err_code = CALCULATION_ERROR;
    else size = A->rows;
    if (err_code  == OK && size == 1) res = A->matrix[0][0];
    else if (err_code  == OK && size == 2) res = s21_determinant_2x2(A);
    else if (err_code  == OK) {
        printf("det befor cicle: %d\n", (double) res);
        for (int i = 0; err_code == OK && i < size; i++){
            term_1 = 1.0;
            term_2 = 1.0;
            for (int j = 0; err_code == OK && j < size; j++){
                term_1 *= A->matrix[j][(i + j + size) % size];
                term_2 *= A->matrix[j][(i - j + size) % size]; 
            }
            res += term_1 - term_2;
        }
    }
    printf("err_code: %d\n", err_code);
    printf("det: %d\n", (double) res);
    if (err_code == OK) {
        if (s21_is_valid_element((double)res)) *result = (double) res;
        else err_code = CALCULATION_ERROR;
    }
    return err_code;
}