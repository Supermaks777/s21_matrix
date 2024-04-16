#include "s21_matrix.h"

void main(){
    matrix_t my_matrix;
    printf("%d", s21_create_matrix(3,4,&my_matrix));
    s21_remove_matrix(&my_matrix);
}