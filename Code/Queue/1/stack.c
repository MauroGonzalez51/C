#include "stack.h"

void createStack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, int value) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->value = value;
    newElement->nextElement = stack->top;

    stack->top = newElement;
    stack->size++;
}

int pop(Stack *stack) {
    if (isEmptyStack(stack)) {
        return -1;
    }

    Node *poppedElement = stack->top;
    stack->top = poppedElement->nextElement;
    stack->size--;

    int value = poppedElement->value;
    free(poppedElement);
    return value;
}

int isEmptyStack(Stack *stack) {
    return stack->size == 0;
}