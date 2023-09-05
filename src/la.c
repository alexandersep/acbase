#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> 
#include "../include/la.h"

struct la* la_init(int size) {
    struct la* la = malloc(sizeof(struct la));
    la->arr = malloc(sizeof(la->arr[0]) * size);
    assert(la != NULL);
    la->size = size;
    la->filled = 0;
    return la;
}

void la_insert(struct la* la, float val) {
    int size = la->size;
    if (la->filled == size) {
        float* ret = realloc(la->arr, sizeof(la->arr[0]) * size * 2);
        if (ret == NULL) {
            la_free(la);
            assert(la->arr != NULL);
        } else {
            la->arr = ret;
        }
        la->size = size * 2;
    }
    la->arr[la->filled] = val;
    la->filled++;
}

void la_insert_times(struct la* la, float val, int times) {
    for (int i = 0; i < times; i++) {
        la_insert(la, val);
    }
}

void la_remove(struct la* la) {
    assert(la->filled > 0);
    la->filled--;
    la->arr[la->filled] = 0;
}

void la_reverse(struct la* la) {
    int j = la->filled - 1;
    for (int i = 0; i < j; i++, j--) {
        float temp = la->arr[i];
        la->arr[i] = la->arr[j];
        la->arr[j] = temp;
    }
}

void la_print(struct la* la) {
    printf("Printing la in order\n");
    printf("-------------------------------\n");
    for (int i = 0; i < la->filled; i++) {
        printf("%f ", la->arr[i]);
    }
    printf("\n-------------------------------\n");
}

void la_print_reverse(struct la* la) {
    printf("Printing la in reverse order\n");
    printf("-------------------------------\n");
    for (int i = la->filled - 1; i >= 0; i--) {
        printf("%f ", la->arr[i]);
    }
    printf("\n-------------------------------\n");
}

void la_free(struct la* la) {
    free(la->arr);
    free(la);
}
