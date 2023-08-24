#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

bool areParenthesesBalanced(const char *expression) {
    Stack stack;

    createStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            Element element;
            element.item = '(';
            push(&stack, element);
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) {
                return false; // Si hay un paréntesis cerrado y la pila está vacía, no está balanceado
            } else {
                pop(&stack); // Si hay un paréntesis cerrado y hay un paréntesis abierto en la pila, los sacamos
            }
        }
    }

    return isEmpty(&stack);
}

int main(void) {
    char expression[100];

    printf("Ingrese una expresion: ");
    scanf("%s", expression);

    (areParenthesesBalanced(expression)) ?
        printf("Balanceados\n") : printf("No balanceados\n");
    

    return EXIT_SUCCESS;
}