#ifndef STACK_H
#define STACK_H

struct stack {
    int size;
    int idx;
    float* arr;
};

// Stack init
// Summary: Initialise a Stack struct pointer on the heap
// Returns: Stack Struct Pointer
struct stack* stack_init(int size);

// Stack push
// Summary: Push an element on top of the stack
//          If stack is half full, stack is doubled
void stack_push(struct stack* stack, float val);

// Stack peek
// Summary: Peek at the top element on the stack 
// Returns: float or assert error if nothing on top of stack
float stack_peek(struct stack* stack);

// Stack pop
// Summary: Pop an element on top of the stack
// Returns: float or assert error if nothing on top of stack 
float stack_pop(struct stack* stack);

// Stack free
// Summary: Frees the Stack using free
void stack_free(struct stack* stack);

#endif
