#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int length) {
  int max_pos = 0, min_pos = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] > arr[max_pos]) {
      max_pos = i;
    }
    if (arr[i] < arr[min_pos]) {
      min_pos = i;
    }
  }
  int tmp = arr[min_pos];
  arr[min_pos] = arr[max_pos];
  arr[max_pos] = tmp;
}

int main(void) {
  int flag = 0;
  int capacity = 2;
  int length = 0;
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
      int *new_arr = (int *)realloc(arr, capacity * sizeof(int));
      if (new_arr == NULL) {
        flag = 1;
      } else {
        arr = new_arr;
      }
    }
    if (num != -1) {
      arr[length++] = num;
    }
    if (num == -1) {
      break;
    }
    if (ch != ' ' && ch != '\t') {
      break;
    }
  }
  swap(arr, length);
  if (flag == 0 && length > 0) {
    for (int i = 0; i < length; i++) {
      if (i == length - 1) {
        printf("%d", arr[i]);
      } else {
        printf("%d ", arr[i]);
      }
    }
  }
  if (flag == 1) {
    printf("n/a");
  }
  free(arr);
  return flag;
}