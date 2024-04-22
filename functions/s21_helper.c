#include "../s21_matrix.h"

/**
 * @brief проверяет равенство размеров матрицы
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
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
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @return результат проверки (int)
 * @retval 0 - содержимые матриц НЕ равны.
 * @retval 1 - содержимые матриц равны.
 */
int s21_eq_content (matrix_t A, matrix_t B){
    int result = SUCCESS;
    if (!s21_eq_size(A, B)) result = FAILURE;
    for (int i = 0; i < A.rows && result == SUCCESS; i++) {
        for (int j = 0; j < A.columns && result == SUCCESS; j++){
            result = s21_eq_element(A.matrix[i][j], B.matrix[i][j]);
        }
    }
    return result;
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
    int result = SUCCESS;
    if (!source) result = FAILURE;
    else if (!source->matrix) result = FAILURE;
    else if (source->rows < 1 || source->columns < 1) result = FAILURE;
    for (int i = 0; result == SUCCESS && i < source->rows; i++){
        if (!source->matrix[i]) result = 0;
        for (int j = 0; result == SUCCESS && j < source->columns; j++){
            if (!s21_is_valid_element(source->matrix[i][j])) result = FAILURE;
        }
    }
    return result;
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
 * @return определитель (long double)
  */
long double s21_determinant_2x2(matrix_t* A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

/**
 * @brief рассчитывает минор (определитель усеченной матрицы)
 *
 * @param source исходная матрица
 * @param row строка заданного элемента исходной матрицы (int)
 * @param column столбец заданного элемента исходной матрицы (int)
 * @param err_code указатель на код ошибки (* int)
 * @return резульат (double)
 */
double s21_get_minor(matrix_t* source, int row, int column, int * err_code) {
//исходные данные считаю корректными
    long double result = 0;
    matrix_t sub_matrix = {0};
    *err_code = s21_create_sub_matrix(source, row, column, source->rows - 1, &sub_matrix);
    if (*err_code == OK) {
        if (source->rows == 3) result = s21_determinant_2x2(&sub_matrix);
        else {
            double element_value;
            int element_sign;
            for (int i = 0; i < (source->rows - 1) && *err_code == OK; i++){
                element_sign = (i %  2) ? 1 : -1;
                element_value = source->matrix[0][i];
                result += element_sign * element_value * s21_get_minor(&sub_matrix, 0, i, err_code);
            }
        }
        s21_remove_matrix(&sub_matrix);
    }
    if (!s21_is_valid_element((double)result)) *err_code = CALCULATION_ERROR;
    return (double) result;
}

/**
 * @brief создает субматрицу, за исключением указанного столбца и строки
 *
 * @param source исходная матрица (matrix_t *)
 * @param row_del строка заданного элемента исходной матрицы (int)
 * @param column_del столбец заданного элемента исходной матрицы (int)
 * @param size разрер субматрицы матрицы (int)
 * @param result указатель результат (*result)
 * @return код ошибки (int)
 */
int s21_create_sub_matrix(matrix_t* source, int row_del, int column_del, int size, matrix_t* result) {
    int err_code = 0;
    err_code = s21_create_matrix(size, size, result);
    // printf("size: %d\n", size);
    // printf("after create submatrix check: %d\n", err_code);
    if (err_code == OK) {
        for (int row_src = 0, row_res = 0;  row_src <= size; row_src++){
            if (row_src == row_del) continue;
            for (int column_src = 0, column_res = 0; column_src <= size; column_src++){
                if (column_src == column_del) continue;
                // printf("%d -- %d -- %d -- %d\n", row_src, row_res, column_src, column_res);
                result->matrix[row_res][column_res] = source->matrix[row_src][column_src];
                column_res++;
            }
            row_res++;
        }
    }
    // printf("after fill submatrix check: %d\n", err_code);
    // s21_print_matrix(result); 
    // printf("\n");
    return err_code;
}

/**
 * @brief заполняет матрицу арифметической последовательностью, заданной началом и шагом
 *
 * @param source исходная матрица
 * @param start значение первого элемента матрицы (double)
 * @param step шаг арифметической последовательности (double)
 */
void s21_initialize_matrix(matrix_t *source, double start, double step) {
    if (s21_is_valid_matrix(source)) {
        double current_value = start;
        for (int i = 0; i < source->rows; i++) {
            for (int j = 0; j < source->columns; j++) {
                source->matrix[i][j] = current_value;
                current_value += step;
            }
        }
    }
}

/**
 * @brief вывод на экран матрицы
 *
 * @param source исходная матрица
 */
void s21_print_matrix(matrix_t *source) {
    if (s21_is_valid_matrix(source)) {
        for (int i = 0; i < source->rows; i++) {
            for (int j = 0; j < source->columns; j++) printf("%f\t", source->matrix[i][j]);
            printf("\n");
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
int s21_is_valid_for_det(matrix_t * source){
    int result = SUCCESS;
    if (!source) result = FAILURE;
    else if (!source->matrix) result = FAILURE;
    else if (source->rows < 1 || source->columns < 1) result = FAILURE;
    for (int i = 0; result == SUCCESS && i < source->rows; i++){
        if (!source->matrix[i]) result = 0;
        for (int j = 0; result == SUCCESS && j < source->columns; j++){
            if (!s21_is_valid_element(source->matrix[i][j])) result = FAILURE;
        }
    }
    return result;
}