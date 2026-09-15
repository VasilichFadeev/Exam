#include <stdio.h>
#include <stdlib.h>

// void pairs(int *arr, int length) {
//     int first = 1;
//     for (int i = 0; i < length; i++) {
//         int count = 0;
//         for (int j = 0; j < length; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//             }
//         }
//         if (count == 1) {
//             if (!first) printf(" ");
//             printf("%d", arr[i]);
//             first = 0;
//         }
//     }
// }

// int main(void) {
//     int flag = 0;
//     int length = 0;
//     int capacity = 2;
//     int *arr = (int *)malloc(capacity * sizeof(int));
//     if (arr == NULL) {
//         flag = 1;
//     }
//     int num;
//     char ch;
//     while (flag == 0) {
//         int res = scanf("%d%c", &num, &ch);
//         if (res != 2) {
//             flag = 1;
//         }
//         if (length >= capacity) {
//             capacity *= 2;
//             int *buffer = (int *)realloc(arr, capacity * sizeof(int));
//             if (buffer == NULL) {
//                 flag = 1;
//             } else {
//                 arr = buffer;
//             }
//         }
//         if (num == -1) {
//             break;
//         }
//         if (num != -1) {
//             arr[length++] = num;
//         }
//         if (ch != ' ' && ch != '\t') {
//             flag = 1;
//             break;
//         }
//     }
//     if (flag == 0 && length > 0) {
//         pairs(arr, length);
//     }
//     if (flag == 1) {
//         printf("n/a");
//     }
//     free(arr);
//     return flag;
// }

#include <stdio.h>
#include <stdlib.h>

int **multiply(int **matrix1, int **matrix2, int size) {
  int **result = (int **)malloc(size * sizeof(int *));
  if (result == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    result[i] = (int *)malloc(size * sizeof(int));
    if (result[i] == NULL) {
      for (int k = 0; k < i; k++) {
        free(result[k]);
      }
      free(result);
      return NULL;
    }
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = 0;
      for (int k = 0; k < size; k++) {
        result[i][j] += (int)matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

int main(void) {
  int flag = 0;
  int size;
  char ch;
  int res1 = scanf("%d%c", &size, &ch);
  if (res1 != 2 || size <= 0) {
    flag = 1;
  }

  int **matrix1 = NULL;
  int **matrix2 = NULL;

  if (flag == 0) {
    matrix1 = (int **)malloc(size * sizeof(int *));
    if (matrix1 == NULL) {
      flag = 1;
    } else {
      for (int i = 0; i < size; i++) {
        matrix1[i] = (int *)malloc(size * sizeof(int));
        if (matrix1[i] == NULL) {
          flag = 1;
        }
      }
    }
  }

  if (flag == 0) {
    matrix2 = (int **)malloc(size * sizeof(int *));
    if (matrix2 == NULL) {
      flag = 1;
    } else {
      for (int i = 0; i < size; i++) {
        matrix2[i] = (int *)malloc(size * sizeof(int));
        if (matrix2[i] == NULL) {
          flag = 1;
        }
      }
    }
  }

  if (flag == 0) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int res = scanf("%d%c", &matrix1[i][j], &ch);
        if (res != 2) {
          flag = 1;
        }
      }
    }
  }

  if (flag == 0) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int res = scanf("%d%c", &matrix2[i][j], &ch);
        if (res != 2) {
          flag = 1;
        }
      }
    }
  }

  if (flag == 0) {
    int **result = multiply(matrix1, matrix2, size);
    if (result == NULL) {
      flag = 1;
    } else {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if (j == size - 1) {
            printf("%d", result[i][j]);
          } else {
            printf("%d ", result[i][j]);
          }
        }
        if (i != size - 1) {
          printf("\n");
        }
      }
      for (int i = 0; i < size; i++) {
        free(result[i]);
      }
      free(result);
    }
  }

  if (flag == 1) {
    printf("n/a");
  }

  if (matrix1 != NULL) {
    for (int i = 0; i < size; i++) {
      free(matrix1[i]);
    }
    free(matrix1);
  }

  if (matrix2 != NULL) {
    for (int i = 0; i < size; i++) {
      free(matrix2[i]);
    }
    free(matrix2);
  }

  return flag;
}