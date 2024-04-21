#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    return (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || !s21_eq_size(*A, *B) || !s21_eq_content(*A, *B)) ? FAILURE : SUCCESS;
}


