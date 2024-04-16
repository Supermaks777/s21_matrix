#include "s21_matrix.h"


/**
 * @brief создает матрицу заданного размера (вариант rows+1 массивами)
 * валидация данных: result на существование, размеры матрицы на корректность, выделение памяти под строки
 * @param rows количество строк (int)
 * @param columns количество столбцов (int)
 * @param result ссылка на структура с матрицей
 * @return код ошибки
 * @retval 0 - OK
 * @retval 1 - Ошибка, некорректная матрица
 * @retval 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result){
    int err_code = 0;
    if (!result) err_code = 1;
    else if (rows < 1 || columns < 1 || rows == columns == 1) err_code = 1;
    else {
        // Инициализация структуры
        result->rows = rows;
        result->columns = columns;

        // Выделение памяти под двумерный массив
        result->matrix = (double **)malloc(rows * sizeof(double *));
        for (int i = 0; i < rows && !err_code; i++) {
            result->matrix[i] = (double *)malloc(columns * sizeof(double));
            if (!result->matrix[i]) err_code = 1;
        }

        // Инициализация матрицы нулями
        for (int i = 0; i < rows && !err_code; i++) {
            for (int j = 0; j < columns; j++) {
                result->matrix[i][j] = 0.0;
            }
        }    
    }

//очищение памяти на случай, если ошибка случилась в процессе выделения памяти на строки (т.е. какие то строки уже были выделены)
    if (err_code && !!result){
        for (int i = 0; i < rows; i++) if (!!result->matrix[i]) free(result->matrix[i]);
    }
    return err_code;
}