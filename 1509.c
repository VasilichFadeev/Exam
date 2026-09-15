// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int count(char str[1000]) {
//     int sentence_counter = 0;
//     int prev_end = 0;
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
//             if (prev_end == 0) {
//                 sentence_counter++;
//                 prev_end = 1;
//             }
//         } else {
//             prev_end = 0;
//         }
//     }
//     return sentence_counter;
// }

// int main(void) {
//     FILE *file;
//     char name[1000];
//     char str[1000];
//     fgets(name, sizeof(name), stdin);
//     name[strcspn(name, "\n")] = '\0';
//     file = fopen(name, "r");
//     if (file == NULL) {
//         printf("n/a");
//         return 1;
//     }
//     int len = 0;
//     char c;
//     while ((c = fgetc(file)) != EOF && len < (int)sizeof(str) - 1) {
//         str[len++] = c;
//     }
//     str[len] = '\0';
//     printf("%d", count(str));
//     fclose(file);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main(void) {
  char str[1000];
  char substr[1000];
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  fgets(substr, sizeof(substr), stdin);
  substr[strcspn(substr, "\n")] = '\0';

  int sublen = strlen(substr);
  if (sublen == 0) {
    printf("%s\n", str);
    return 0;
  }

  char *last = NULL;
  char *p = str;
  while ((p = strstr(p, substr)) != NULL) {
    last = p;
    p++;
  }

  if (last == NULL) {
    printf("%s\n", str);
  } else {
    memmove(last, last + sublen, strlen(last + sublen) + 1);
    printf("%s\n", str);
  }

  return 0;
}