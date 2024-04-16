#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    // int result = SUCCESS;
    // if (!A || !B) result = FAILURE;
    // else if (!s21_eq_size(*A, *B)) result = FAILURE;
    // else if (!s21_eq_content(*A, *B)) result = FAILURE;
    // return result;
    return !!A && !!B && !s21_eq_size(*A, *B) && !s21_eq_content(*A, *B) ? SUCCESS : FAILURE;
}


