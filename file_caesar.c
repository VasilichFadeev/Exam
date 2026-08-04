#include <stdio.h>
#include <string.h>

int main(void) {
  char str[1000];
  int key;
  FILE *file;
  file = fopen("1.txt", "r");
  if (file == NULL) {
    printf("n/a");
  } else {
    fgets(str, sizeof(str), file);
    fclose(file);
    scanf("%d", &key);
    key = ((key % 26) + 26) % 26;
    for (int i = 0; str[i] != '\0'; i++) {
      char c = str[i];
      if (c >= 'a' && c <= 'z') {
        str[i] = 'a' + (c - 'a' + key) % 26;
      }
      if (c >= 'A' && c <= 'Z') {
        str[i] = 'A' + (c - 'A' + key) % 26;
      }
    }
    printf("%s", str);
  }
  return 0;
}