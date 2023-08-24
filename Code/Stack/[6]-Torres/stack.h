#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack {
    int *items;
    int maxSize;
    int top;
} Stack;

Stack* createStack(int maxSize);
int isEmpty(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);


#endif