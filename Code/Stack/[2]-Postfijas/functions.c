#include "functions.h"

float calcule(char operation, float a, float b) {
    float result = 0;

    switch (operation) {
        case '+': 
            result = a + b;
            break;
    
        case '-': 
            result = a - b;
            break;

        case '*':
            result = a * b;
            break;
        
        case '/':
            result = a / b;
            break;

        case '$':
            result = pow(a, b);
            break;
    }

    return result;
}

int isdigit(char element) {
    return (element >= '0' && element <= '9');
}

int isOperator(char element) {
    return (element == '+' || element == '-' || element == '*' || element == '/' || element == '$');
}

void evaluatePostfix(char *expression) {
    Stack stack;

    createStack(&stack);

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        char element = expression[i];

        if (isdigit(element)) {
            Element item;
            item.number = (float) (element - '0');
            push(&stack, item);
        } else {
            Element *elementB = pop(&stack);
            Element *elementA = pop(&stack);

            Element result;

            result.number = calcule(element, elementA -> number, elementB -> number);
            push(&stack, result);
        }
    }

    Element *result = pop(&stack);
    printf("Result: %f\n", result -> number);
}