#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef struct {
  char first_name[N];
  char second_name[N];
  int height;
} Man;

int main(void) {
  int flag = 0;
  int capacity = 2;
  int length = 0;
  Man *men = (Man *)malloc(capacity * sizeof(Man));
  if (men == NULL) {
    flag = 1;
  }

  char line[100];
  while (flag == 0 && fgets(line, sizeof(line), stdin) != NULL) {
    if (line[0] == '\n') {
      break;
    }

    Man tmp;
    int res = sscanf(line, "%49s %49s %d", tmp.first_name, tmp.second_name,
                     &tmp.height);
    if (res != 3) {
      break;
    }

    if (length >= capacity) {
      capacity *= 2;
      Man *new_man = (Man *)realloc(men, capacity * sizeof(Man));
      if (new_man == NULL) {
        flag = 1;
        break;
      }
      men = new_man;
    }
    men[length++] = tmp;
  }

  char input[100];
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  int height_counter = 0;
  int divider = 0;
  for (int i = 0; i < length; i++) {
    if (strcmp(input, men[i].first_name) == 0 ||
        strcmp(input, men[i].second_name) == 0) {
      height_counter += men[i].height;
      divider++;
    }
  }

  if (divider != 0) {
    printf("%d\n", height_counter / divider);
  } else {
    printf("n/a");
  }

  free(men);
  return flag;
}