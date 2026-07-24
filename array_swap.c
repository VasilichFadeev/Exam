#include <stdio.h>
#include <stdlib.h>

void swap(int *array, int length) {
    int max_pos = 0, min_pos = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > array[max_pos]) {
            max_pos = i;
        }
        if (array[i] < array[min_pos]) {
            min_pos = i;
        }
    }
    int tmp = array[max_pos];
    array[max_pos] = array[min_pos];
    array[min_pos] = tmp;
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
            int *new_array = (int *)realloc(array, capacity * sizeof(int));
            if (new_array == NULL) {
                flag = 1;
            } else {
                array = new_array;
            }
        }
        if (flag == 0) {
            if (num != -1) {
                array[length++] = num;
            }
            if (num == -1) {
                break;
            }
            if (ch != ' ' && ch != '\t') {
                flag = 1;
            }
        }
    }
    swap(array, length);
    if (flag == 0 && length > 0) {
        for (int i = 0; i < length; i++) {
            if (i == length - 1) {
                printf("%d", array[i]);
            } else {
                printf("%d ", array[i]);
            }
        }
    }
    if (flag == 1) {
        printf("n/a");
    }
    free(array);
    return flag;
}