#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int flag = 0;
  int capacity = 2;
  int length = 0;
  int *array = (int *)malloc(capacity * sizeof(int));
  if (array == NULL) {
    flag = 1;
  }
  int num;
  char ch;
  while (flag == 0 && scanf("%d%c", &num, &ch) == 2) {
    if (length >= capacity) {
      capacity *= 2;
      int *new_array = (int *)realloc(array, capacity * sizeof(int));
      if (new_array == NULL) {
        flag = 1;
      } else {
        array = new_array;
      }
    }
    if (flag == 0) {
      array[length++] = num;
      if (ch == '\n') {
        break;
      }
    }
    if (flag == 0 && length > 0) {
      int c;
      do {
        c = getchar();
      } while (c == ' ' || c == '\t');
      if (c != '\n' && c != EOF) {
        flag = 1;
      }
    }
  }
  if (flag == 0 && length > 0) {
    for (int i = 0; i < length; i++) {
      if (i == length - 1) {
        printf("%d", array[i]);
      } else {
        printf("%d ", array[i]);
      }
    }
  } else {
    flag = 1;
  }
  if (flag == 1) {
    printf("n/a");
  }
  free(array);
}