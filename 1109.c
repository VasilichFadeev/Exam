#include <stdio.h>
#include <stdlib.h>

// void reverse(int *arr, int length) {
//     int i = 0;
//     int j = length - 1;
//     while (i < j) {
//         int tmp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = tmp;
//         i++;
//         j--;
//     }
// }

// void remove_duplicates(int *arr, int length) {
//     for (int i = 0; i < length; i++) {
//         int seen = 0;
//         for (int j = i + 1; j < length; j++) {
//             if (arr[i] == arr[j]) {
//                 seen = 1;
//                 break;
//             }
//         }
//         if (seen == 0) {
//             printf("%d", arr[i]);
//         }
//     }
// }

void swap(int *arr, int length) {
  int max_pos = 0, min_pos = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] > arr[max_pos]) {
      max_pos = i;
    }
    if (arr[i] < arr[max_pos]) {
      min_pos = i;
    }
  }
  int tmp = arr[min_pos];
  arr[min_pos] = arr[max_pos];
  arr[max_pos] = tmp;
}

int main(void) {
  int flag = 0;
  int length = 0;
  int capacity = 2;
  int *arr = (int *)malloc(capacity * sizeof(int));
  if (arr == NULL) {
    flag = 1;
  }
  int num;
  char ch;
  while (flag == 0) {
    int res = scanf("%d%c", &num, &ch);
    if (res != 2) {
      flag = 1;
      break;
    }
    if (length >= capacity) {
      capacity *= 2;
      int *buffer = (int *)realloc(arr, capacity * sizeof(int));
      if (buffer == NULL) {
        flag = 1;
      } else {
        arr = buffer;
      }
    }
    if (num == -1) {
      break;
    }
    if (num != -1) {
      arr[length++] = num;
    }
    if (ch != ' ' && ch != 't') {
      flag = 1;
      break;
    }
  }
  if (flag == 0 && length > 0) {
    // reverse(arr, length);
    swap(arr, length);
    for (int i = 0; i < length; i++) {
      if (i == length - 1) {
        printf("%d", arr[i]);
      } else {
        printf("%d ", arr[i]);
      }
    }
    // remove_duplicates(arr, length);
  }
  if (flag == 1) {
    printf("n/a");
  }
  free(arr);
  return flag;
}