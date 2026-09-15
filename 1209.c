#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// int main(void) {
//     int flag = 0;
//     int n;
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         flag = 1;
//     }
//     int *a = (int *)malloc(n * sizeof(int));
//     if (a == NULL) {
//         flag = 1;
//     }
//     int *b = (int *)malloc(n * sizeof(int));
//     if (b == NULL) {
//         flag = 1;
//     }
//     for (int i = 0; i < n; i++) {
//         if (scanf("%d", &a[i]) != 1) {
//             flag = 1;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (scanf("%d", &b[i]) != 1) {
//             flag = 1;
//         }
//     }
//     int result = 0;
//     for (int i = 0; i < n; i++) {
//         result += a[i] * b[i];
//     }
//     if (flag == 0) {
//         printf("%d", result);
//     }
//     if (flag == 1) {
//         printf("n/a");
//     }
//     free(a);
//     free(b);
//     return flag;
// }

// void bothsides(int *arr, int length) {
//     int i = 0;
//     int j = length - 1;
//     int first = 1;
//     while (i <= j) {
//         if (i == j) {
//             if (first != 1) {
//                 printf(" ");
//             }
//             printf("%d", arr[i]);
//             break;
//         }
//         if (first != 1) {
//             printf(" ");
//         }
//         printf("%d", arr[i]);
//         first = 0;
//         printf(" %d", arr[j]);
//         i++;
//         j--;
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
//         bothsides(arr, length);
//     }
//     if (flag == 1) {
//         printf("n/a");
//     }
//     free(arr);
//     return flag;
// }

void palindrom(char *arr, int length) {
  int i = 0;
  int j = length - 1;
  int is_pal = 1;
  while (i < j) {
    if (tolower(arr[i]) != tolower(arr[j])) {
      is_pal = 0;
      break;
    }
    i++;
    j--;
  }
  if (is_pal) {
    printf("YES");
  } else {
    printf("NO");
  }
}

int main(void) {
  int flag = 0;
  int length = 0;
  int capacity = 2;
  char *arr = (char *)malloc(capacity * sizeof(char));
  if (arr == NULL) {
    flag = 1;
  }
  char ch;
  while (flag == 0) {
    scanf("%c", &ch);
    if (length >= capacity) {
      capacity *= 2;
      char *buffer = (char *)realloc(arr, capacity * sizeof(char));
      if (buffer == NULL) {
        flag = 1;
      } else {
        arr = buffer;
      }
    }
    if (length >= 100) {
      flag = 1;
      break;
    }
    if (ch == '\n') {
      break;
    } else {
      arr[length++] = ch;
    }
  }
  if (flag == 0 && length > 0) {
    palindrom(arr, length);
  }
  if (flag == 1) {
    printf("n/a");
  }
  free(arr);
  return flag;
}