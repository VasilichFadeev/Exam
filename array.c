#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int length;
  int flag = 0;
  char input_check;
  if ((scanf("%d%c", &length, &input_check) != 2) || (input_check != '\n')) {
    flag = 1;
  } else {
    int *array = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
      if (!scanf("%d", &array[i])) {
        flag = 1;
      }
    }
    if (flag == 0) {
      for (int i = 0; i < length; i++) {
        if (i != length - 1) {
          printf("%d ", array[i]);
        } else {
          printf("%d", array[i]);
        }
      }
    }
    free(array);
  }
  if (flag == 1) {
    printf("n/a");
  }
  return flag;
}