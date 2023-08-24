#include "functions.h"

void binaryRepresentation(Stack *stack, int decimalNumber) {
    while (decimalNumber > 0) {
        Element element;
        element.number = decimalNumber % 2;
        push(stack, element);
        decimalNumber /= 2;
    }
}

void printStack(Stack *stack) {
    printf("Result: ");
    while (size(stack) > 0) {
        Element *element = pop(stack);
        printf("%d", element->number);
        free(element);
    }
    printf("\n");
}
