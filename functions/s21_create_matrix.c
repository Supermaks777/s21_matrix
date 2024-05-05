#include "../s21_matrix.h"

/**
 * @brief создает матрицу заданного размера (вариант rows+1 массивами)
 * валидация данных: result на существование, размеры матрицы на корректность,
 * выделение памяти под строки
 * @param rows количество строк (int)
 * @param columns количество столбцов (int)
 * @param result ссылка на структура с матрицей
 * @return код ошибки
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_code = (result && rows > 0 && columns > 0) ? OK : INCORRECT_MATRIX;

  if (err_code == OK) {
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows && err_code == OK; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        err_code = INCORRECT_MATRIX;
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
        result->matrix = NULL;
      }
    }
  }
  if (err_code == OK) {
    result->rows = rows;
    result->columns = columns;
  }
  return err_code;
}