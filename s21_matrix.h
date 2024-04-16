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



//helper
int s21_eq_size (matrix_t A, matrix_t B);
int s21_abs(double val);
int s21_eq_element (double val_1, double val_2);
int s21_eq_content (matrix_t A, matrix_t B);


#endif