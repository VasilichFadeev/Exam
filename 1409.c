#include <stdio.h>
#include <string.h>

// int main(void) {
//     int flag = 0;
//     char name[1000];
//     char string[1000];
//     int key;
//     scanf("%s", name);
//     FILE *file;
//     file = fopen(name, "r");
//     if (file == NULL) {
//         flag = 1;
//     }
//     int len = 0;
//     int c;
//     while ((c = fgetc(file)) != EOF && len < (int)sizeof(string) - 1) {
//         string[len++] = c;
//     }
//     string[len] = '\0';
//     fclose(file);
//     char ch;
//     int res = scanf("%d%c", &key, &ch);
//     if (res != 2) {
//         flag = 1;
//     }
//     if (flag == 0) {
//         key = ((key % 26) + 26) % 26;
//         for (int i = 0; string[i] != '\0'; i++) {
//             char c = string[i];
//             if (c >= 'a' && c <= 'z') {
//                 string[i] = 'a' + (c - 'a' + key) % 26;
//             }
//             if (c >= 'A' && c <= 'Z') {
//                 string[i] = 'A' + (c - 'A' + key) % 26;
//             }
//         }
//         printf("%s", string);
//     }
//     if (flag == 1) {
//         printf("n/a");
//     }
//     return flag;
// }

void space_print(char str[1000]) {
  int counter = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      counter++;
    } else {
      counter = 0;
    }
    if (counter > 1) {
      continue;
    } else {
      printf("%c", str[i]);
    }
  }
}

int main(void) {
  char str[1000];
  char name[1000];
  scanf("%s", name);
  FILE *file;
  file = fopen(name, "r");
  if (file == NULL) {
    return 1;
  }
  int len = 0;
  int c;
  while ((c = fgetc(file)) != EOF && len < (int)sizeof(str) - 1) {
    str[len++] = c;
  }
  str[len] = '\0';
  fclose(file);
  space_print(str);
  return 0;
}