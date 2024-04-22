#include "s21_matrix.h"

int main(){
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  printf("create_1: %d\n",s21_create_matrix(1, 1, &A));
  printf("create_2: %d\n", s21_create_matrix(1, 1, &eq_matrix));
  A.matrix[0][0] = 21;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;

  printf("inverse: %d\n",s21_inverse_matrix(&A, &result));
  printf("compare^ %d", s21_eq_matrix(&result, &eq_matrix));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);

    return 0;
}