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
 * @brief проверяет валидность матрицы.  \n
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
 * @param val структура с матрицей (double)
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
 * @param A первая матрица
 * @param B вторая матрица
 * @return результат проверки (int)
 * @retval 0 - размеры НЕ совместимы.
 * @retval 1 - размеры совместимы.
 */
int s21_compatibility_size (matrix_t A, matrix_t B) {
    return A.columns == B.rows;
}