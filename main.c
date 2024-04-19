#include "s21_matrix.h"

void main(){
    printf("\ni'm here\n");
    matrix_t my_matrix_1, my_matrix_2, my_matrix_3;

    s21_create_matrix(5,6,&my_matrix_1);
    s21_initialize_matrix(&my_matrix_1, 1.0, 2.0);
    s21_print_matrix(&my_matrix_1);

    // s21_create_matrix(5,6,&my_matrix_2);
    // s21_initialize_matrix(&my_matrix_2, -1.0, -2.0);
    // s21_print_matrix(&my_matrix_3);

    // s21_create_matrix(5,6,&my_matrix_3);
    // s21_sum_matrix(&my_matrix_1, &my_matrix_2, &my_matrix_3);
    // s21_print_matrix(&my_matrix_3);

    // s21_remove_matrix(&my_matrix_1);
    // s21_remove_matrix(&my_matrix_2);
    // s21_remove_matrix(&my_matrix_3);
    // printf("\nthis is very good\n");


}