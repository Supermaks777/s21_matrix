#include "s21_matrix.h"

int main(){
  // успех: матрица с заданными значениями элементов
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  s21_print_matrix(&A);
  printf("\n");
  int res = s21_determinant(&A, &det);
  printf("det (result): %f (%d)", det, res);
  s21_remove_matrix(&A);


    return 0;
}