#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h" 

// ! Just for debugging ...
void printStack(Stack *stack) {
    Element *current = stack->front;

    while (current != NULL) {
        printf("[%s]\n", current->item);
        current = current->nextElement;
    }
}

void evaluatePostfix(char *expression) {
    Stack stack;
    createStack(&stack);

    const char delimiter[] = ",";

    char *token = strtok(expression, delimiter);

    while (token != NULL) {
        Element *element = (Element *)malloc(sizeof(Element));
        element->item = (char *)malloc(strlen(token) + 1); 
        strcpy(element->item, token);

        push(&stack, *element);

        token = strtok(NULL, delimiter);
    }

    printStack(&stack);
}

int main() {
    char expression[100];
    printf("Ingrese la expresion postfija: ");
    scanf("%s", expression);

    evaluatePostfix(expression);

    return 0;
}

