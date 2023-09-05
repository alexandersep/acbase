#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/stack.h"

struct stack* stack_init(int size) {
    struct stack* stack = malloc(sizeof(struct stack));
    assert(stack != NULL);
    stack->size = size;
    stack->idx = 0;
    stack->arr = malloc(sizeof(stack->arr[0]) * size);
    return stack;
}

void stack_push(struct stack* stack, float val) {
    int size = stack->size;
    if (stack->idx >= (size / 2) ) {
        size *= 2;
        stack->size = size;
        float* ret = realloc(stack->arr, size);
        if (ret == NULL) {
            stack_free(stack);
            assert(ret != NULL);
        } else {
            stack->arr = ret;
        }
    } 
    stack->idx += 1;
    assert(stack->idx != size); // This should never happen
    stack->arr[stack->idx] = val;
}

float stack_peek(struct stack* stack) {
    assert(stack->idx != 0);
    return stack->arr[stack->idx];
}

float stack_pop(struct stack* stack) {
    assert(stack->idx > 0);
    float res = stack->arr[stack->idx];
    stack->arr[stack->idx] = 0; // nullify previous value
    stack->idx -= 1;
    assert(stack->idx >= 0); // Should always be true
    return res;
}

void stack_free(struct stack* stack) {
    free(stack->arr);
    free(stack);
}
