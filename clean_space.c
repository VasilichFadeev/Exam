#include <stdio.h>
#include <stdlib.h>

int clean_space(char *array, int length) {
    int write_pos = 0;
    int prev_was_space = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == ' ') {
            if (prev_was_space != 1) {
                array[write_pos++] = array[i];
            }
            prev_was_space = 1;
        } else {
            array[write_pos++] = array[i];
            prev_was_space = 0;
        }
    }
    return write_pos;
}

int main(void) {
    int flag = 0;
    int capacity = 2;
    int length = 0;
    char *array = (char *)malloc(capacity * sizeof(char));
    if (array == NULL) {
        flag = 1;
    }
    char ch;
    while (flag == 0) {
        int res = scanf("%c", &ch);
        if (res != 1) {
            flag = 1;
            break;
        }
        if (length >= capacity) {
            capacity *= 2;
            char *buffer = (char *)realloc(array, capacity * sizeof(char));
            if (buffer == NULL) {
                flag = 1;
                break;
            } else {
                array = buffer;
            }
        }
        array[length++] = ch;
        if (ch == '\n') {
            break;
        }
    }
    length = clean_space(array, length);
    for (int i = 0; i < length; i++) {
        printf("%c", array[i]);
    }
    free(array);
    return flag;
}
