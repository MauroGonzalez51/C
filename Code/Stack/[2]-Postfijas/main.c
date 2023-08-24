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

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
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
        
        free(element);
    }

    while (size(&stack) > 1) {
        printf("Iteracion\n");

        Element *element = pop(&stack);

        if (isdigit(element->item[0])) {
            element->number = atoi(element->item);
            push(&stack, *element);
        } else if (isOperator(element->item[0])) {
            Element *result = (Element *)malloc(sizeof(Element));

            Element *operand2 = pop(&stack);
            Element *operand1 = pop(&stack);

            printf("Operand2: %s\n",operand2-> number);
            printf("Operand1: %s\n",operand1-> number);

            if (!isdigit(operand1->item[0]) || !isdigit(operand2->item[0])) {
                printf("Error: Operands are not numbers\n");
                free(result);
                free(operand1);
                free(operand2);
                free(element);
                break; 
            }

            switch (element->item[0]) {
                case '+':
                    result->number = operand1->number + operand2->number;
                    break;
                // Otros casos para otros operadores
            }

            push(&stack, *result);

            free(result);
            free(operand1);
            free(operand2);
    }

    free(element);
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

