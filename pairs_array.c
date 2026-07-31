#include <stdio.h>
#include <stdlib.h>

void pairs(int *array, int length) {
  int used[1000] = {0};
  int printed = 0;
  for (int i = 0; i < length; i++) {
    if (used[i]) {
      continue;
    }
    int found_pair = 0;
    for (int j = i + 1; j < length; j++) {
      if (!used[j] && array[i] == array[j]) {
        used[j] = 1;
        found_pair = 1;
        break;
      }
    }
    if (!found_pair) {
      if (printed > 0) {
        printf(" ");
      }
      printf("%d", array[i]);
      printed++;
    }
  }
}

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
  while (flag == 0) {
    int res = scanf("%d%c", &num, &ch);
    if (res != 2) {
      flag = 1;
      break;
    }
    if (length >= capacity) {
      capacity *= 2;
      int *buffer_array = (int *)realloc(array, capacity * sizeof(int));
      if (buffer_array == NULL) {
        flag = 1;
      } else {
        array = buffer_array;
      }
    }
    if (num != -1) {
      array[length++] = num;
    }
    if (num == -1) {
      break;
    }
    if (ch != ' ' && ch != '\t') {
      break;
    }
  }
  if (flag == 0 && length > 0) {
    pairs(array, length);
  }
  if (flag == 1) {
    printf("n/a");
  }
  free(array);
  return flag;
}