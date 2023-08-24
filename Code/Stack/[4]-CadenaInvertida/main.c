#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char* invertExpression(const char *expression) {
    Stack stack;
    createStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        Element element;
        element.item = expression[i]; 
        push(&stack, element);
    }

    char invertedExpression[100]; 
    int index = 0; 

    while (!isEmpty(&stack)) {
        Element *element = pop(&stack);
        invertedExpression[index] = element->item; 
        index++;
    }

    invertedExpression[index] = '\0'; // Termina la cadena

    char *result = (char *)malloc(strlen(invertedExpression) + 1);
    strcpy(result, invertedExpression);

    return result;
}

int main(void) {
    char expression[100];

    printf("Ingrese una expresion: ");
    scanf("%s", expression);

    char *inverted = invertExpression(expression);
    printf("Invertida: %s\n", inverted);

    free(inverted);

    return EXIT_SUCCESS;
}
