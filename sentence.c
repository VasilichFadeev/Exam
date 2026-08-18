#include <stdio.h>
#include <string.h>

int count_sentences(char str[1000]) {
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            counter++;
            i++;
            while (str[i] == '.' || str[i] == '?' || str[i] == '!') {
                i++;
            }
        } else {
            i++;
        }
    }
    return counter;
}

int main(void) {
    int flag = 0;
    char name[1000];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    char str[1000];
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL) {
        flag = 1;
    } else {
        fgets(str, sizeof(str), file);
        printf("%d", count_sentences(str));
        fclose(file);
    }
    if (flag == 1) {
        printf("n/a");
    }
    return flag;
}