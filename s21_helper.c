#include "s21_matrix.h"

int s21_eq_size (matrix_t A, matrix_t B) {
    return A.rows == B.rows && A.columns == B.columns;
}

int s21_abs(double val){
    return (val < 0.0) ? - val : val;
}

int s21_eq_element (double val_1, double val_2) {
    return abs(val_1 - val_2) < S21_PRECISION;
}

int s21_eq_content (matrix_t A, matrix_t B){
    int result = 1;
    for (int i = 0; i < A.rows && result; i++) {
        for (int j = 0; j < A.columns && result; i++){
            if (s21_eq_element(A.matrix[i][j], B.matrix[i][j])) result = 0;
        }
    }
}

int s21_is_valid_matrix(matrix_t check_matrix){
//проверить: 
//
    return 1;
}

int s21_is_valid_element(double val){
    return !isnan(val) && !isinf(val);
}