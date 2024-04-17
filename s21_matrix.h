#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define S21_PRECISION 1E-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };


int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// int s21_transpose(matrix_t *A, matrix_t *result);
// int s21_calc_complements(matrix_t *A, matrix_t *result);
// int s21_determinant(matrix_t *A, double *result);
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);
// char *s21_matrix_to_str(matrix_t *A, int precision);
// int s21_copy_matrix(matrix_t *source, matrix_t *copy);
// double s21_get_minor(matrix_t *src, int row, int col);


//helper
int s21_eq_size (matrix_t A, matrix_t B);
int s21_abs(double val);
int s21_eq_element (double val_1, double val_2);
int s21_eq_content (matrix_t A, matrix_t B);
int s21_is_valid_matrix(matrix_t * source);
int s21_is_valid_element(double val);
int s21_compatibility_size (matrix_t A, matrix_t B);

#endif