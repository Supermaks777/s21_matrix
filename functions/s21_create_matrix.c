#include "../s21_matrix.h"

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
    int err_code = s21_is_valid_matrix_mini(rows, columns, result);

    if (err_code == OK){
        result->rows = rows;
        result->columns = columns;
        result->matrix = calloc(rows, sizeof(double *));
        for (int i = 0; i < rows && err_code == OK; i++) {
            result->matrix[i] = calloc(columns, sizeof(double));
            if (!result->matrix[i]) err_code = INCORRECT_MATRIX;
        }
    }
//очищение памяти на случай, если ошибка случилась в процессе выделения памяти на строки (т.е. какие то строки уже были выделены)
    if (err_code != OK && !!result && rows > 0 && columns > 0){
        for (int i = 0; i < rows; i++) if (!!result->matrix[i]) free(result->matrix[i]);
    }

    return err_code;
}