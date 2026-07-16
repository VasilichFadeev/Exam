#include <stdio.h>
#include <stdlib.h>

void multiply(int **matrix1, int cols1, int rows1, int **matrix2, int cols2, int rows2, int **result) {
    if (cols1 == rows2) {
        for (int i = 0; i < cols2; i++) {
            for (int j = 0; j < rows1; j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
}

int main(void) {
    int flag = 0;
    int cols1, rows1, cols2, rows2;
    char input_check;
    printf("Введите количество столбцов первой матрицы:\n");
    if (scanf("%d%c", &cols1, &input_check) != 2 || (input_check != '\n')) {
        flag = 1;
    }
    if (flag == 0 ) { printf("Введите количество строк первой матрицы:\n"); }
    if (scanf("%d%c", &rows1, &input_check) != 2 || (input_check != '\n')) {
        flag = 1;
    }
    if (flag == 0 ) { printf("Введите количество столбцов второй матрицы:\n"); }
    if (scanf("%d%c", &cols2, &input_check) != 2 || (input_check != '\n')) {
        flag = 1;
    }
    if (flag == 0 ) { printf("Введите количество строк второй матрицы:\n"); }
    if (scanf("%d%c", &rows2, &input_check) != 2 || (input_check != '\n')) {
        flag = 1;
    }
    if (flag == 0) {
        int **matrix1 = (int **)malloc(cols1 * sizeof(int *));
        for (int i = 0; i < cols1; i++) {
            matrix1[i] = (int *)malloc(rows1 * sizeof(int));
        }
        int **matrix2 = (int **)malloc(cols2 * sizeof(int *));
        for (int i = 0; i < cols2; i++) {
            matrix2[i] = (int *)malloc(rows2 * sizeof(int));
        }
        int **result = (int **)malloc(cols1 * sizeof(int *));
        for (int i = 0; i < cols1; i++) {
            result[i] = (int *)malloc(rows2 * sizeof(int));
        }
        printf("Введите первую матрицу:\n");
        for (int i = 0; i < cols1; i++) {
            for (int j = 0; j < rows1; j++) {
                scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Введите вторую матрицу:\n");
        for (int i = 0; i < cols1; i++) {
            for (int j = 0; j < rows1; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }
        multiply(matrix1, cols1, rows1, matrix2, cols2, rows2, result);
        for (int i = 0; i < cols1; i++) {
            for (int j = 0; j < rows2; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < cols1; i++) {
            free(matrix1[i]);
        }
        free(matrix1);
        for (int i = 0; i < cols2; i++) {
            free(matrix2[i]);
        }
        free(matrix2);
        for (int i = 0; i < cols1; i++) {
            free(result[i]);
        }
        free(result);
    }
    if (flag == 1) {
        printf("n/a");
    }
    return flag;
}