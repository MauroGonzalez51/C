#include "stack.h"

Stack* createStack(int maxSize) {
    Stack *stack = (Stack *) malloc (sizeof(Stack));
    stack -> items = (int *) malloc (maxSize * sizeof(int));
    stack -> maxSize = maxSize;
    stack -> top = -1;
    return stack;
}

int isEmpty(Stack *stack) {
    return stack -> top == -1;
}

void push(Stack *stack, int item) {
    if (stack -> top < stack -> maxSize - 1) {
        stack -> items[++stack->top] = item;
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack -> items[stack->top--];
    }
    return -1;
}