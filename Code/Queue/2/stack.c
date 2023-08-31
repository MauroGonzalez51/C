#include "stack.h"

void createStack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, char value) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->value = value;
    newElement->nextElement = stack->top;

    stack->top = newElement;
    stack->size++;
}

Node* pop(Stack *stack) {
    if (isEmptyStack(stack)) {
        return NULL;
    }

    Node *poppedElement = stack -> top;
    stack -> top = poppedElement -> nextElement;
    stack -> size--;

    return poppedElement;
}

int isEmptyStack(Stack *stack) {
    return stack->size == 0;
}