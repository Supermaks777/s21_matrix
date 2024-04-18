#include "s21_matrix.h"
/**
 * @brief проверяет равенство размеров матрицы
 *
 * @param A первая матрица
 * @param B вторая матрица
 * @return результат проверки (int)
 * @retval 0 - размеры НЕ равны.
 * @retval 1 - размеры равны.
 */
int s21_eq_size (matrix_t A, matrix_t B) {
    return A.rows == B.rows && A.columns == B.columns;
}

/**
 * @brief проверяет равенство двух чисел с заданной точностью
 *
 * @param val_1 первое число (double)
 * @param val_2 второе число (double)
 * @return результат проверки (int)
 * @retval 0 - числа НЕ равны.
 * @retval 1 - числа равны.
 */
int s21_eq_element (double val_1, double val_2) {
    return fabs(val_1 - val_2) < S21_PRECISION;
}

/**
 * @brief проверяет равенство содержимого матриц
 *
 * @param A первая матрица
 * @param B вторая матрица
 * @return результат проверки (int)
 * @retval 0 - содержимые матриц НЕ равны.
 * @retval 1 - содержимые матриц равны.
 */
int s21_eq_content (matrix_t A, matrix_t B){
    int result = 1;
    for (int i = 0; i < A.rows && result; i++) {
        for (int j = 0; j < A.columns && result; i++){
            if (s21_eq_element(A.matrix[i][j], B.matrix[i][j])) result = 0;
        }
    }
}

/**
 * @brief проверяет валидность матрицы. 
 * //проверяемые признаки: указатель на структуру, указатель на матрицу, указатели строк, валидность элементов матрицы
 * @param source структура с матрицей (matrix_t)
 * @return результат проверки (int)
 * @retval 0 - матрица НЕ валидна, т.е. хотя бы одна проверка провалена
 * @retval 1 - матрица корректна
 */
int s21_is_valid_matrix(matrix_t * source){
    int result = 1;
    if (!source || !source->matrix) result = 0;
    if (source->rows < 1 || source->columns < 1 || (source->rows == source->columns == 1)) result = 0;
    for (int i = 0; i < source->rows && result; i++){
        if (!source->matrix[i]) result = 0;
        for (int j = 0; i < source->columns && result; j++){
            if (!s21_is_valid_element(source->matrix[i][j])) result = 0;
        }
    }
    return 0;
}

/**
 * @brief проверяет валидность числа.    \n
 * //проверяемые признаки: число не является бесконечностью и не является НЕ_ЧИСЛО
 * @param val исходное число (double)
 * @return результат проверки (int)
 * @retval 0 - число НЕ корректно
 * @retval 1 - число корректно
 */
int s21_is_valid_element(double val){
    return !isnan(val) && !isinf(val);
}

/**
 * @brief проверяет совместимость размеров матрицы (число столбцов одной матрицы равно число строк другой и наоборот)
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @return результат проверки (int)
 * @retval 0 - размеры НЕ совместимы.
 * @retval 1 - размеры совместимы.
 */
int s21_compatibility_size (matrix_t A, matrix_t B) {
    return A.columns == B.rows;
}

/**
 * @brief рассчитывает определитель матрицы размерности 2
 *
 * @param A исходная матрица (matrix_t)
 * @return определитель (double)
  */
double determinant_2x2(matrix_t* A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

// /**
//  * @brief рассчитывает минор 
//  *
//  * @param src Source matrix.
//  * @param row Selected row.
//  * @param col Selected column.
//  * @return Minor value.
//  * @retval double
//  */
// double s21_get_minor(matrix_t* src, int row, int col) {
//   if (is_incorrect_mat(src)) return 0;
//   int sub_size = src->rows - 1;
//   double res = 0;
//   matrix_t sub_matrix = {0};
//   create_sub_matrix(src, row, col, sub_size, &sub_matrix);
//   if (sub_size == 2)
//     res = determinant_2x2(&sub_matrix);
//   else
//     for (int column = 0; column < sub_size; column++) {
//       int sign = (column % 2 == 0) ? 1 : -1;
//       double value = sub_matrix.matrix[0][column];
//       res += sign * value * s21_get_minor(&sub_matrix, 0, column);
//     }
//   s21_remove_matrix(&sub_matrix);
//   return res;
// }
// void create_sub_matrix(matrix_t* src, int row, int col, int size,
//                        matrix_t* result) {
//   if (s21_create_matrix(size, size, result)) return;
//   for (int r = 0, res_r = 0; r <= size; r++) {
//     if (r == row) continue;
//     for (int c = 0, res_c = 0; c <= size; c++) {
//       if (c == col) continue;
//       result->matrix[res_r][res_c] = src->matrix[r][c];
//       res_c++;
//     }
//     res_r++;
//   }
// }