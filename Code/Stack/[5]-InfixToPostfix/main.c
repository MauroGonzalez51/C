#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"

int isValidCharacter(char c) {
    return isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

void filterExpression(char *infixExpression) {
    Stack stack;

    createStack(&stack);

    const char delimiter[] = " ";  

    char *token = strtok(infixExpression, delimiter);

    while (token != NULL) {
        if (isValidCharacter(token[0])) {  
            Element *element = (Element *) malloc(sizeof(Element));
            element->item = (char *) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(element->item, token);
            push(&stack, *element);
            free(element);
        }

        token = strtok(NULL, delimiter);
    }

    while (stack.front != NULL) {
        Element *element = pop(&stack);
        printf("%s,", element->item);
        free(element->item);  
        free(element);
    }

    printf("\n");
}

int main(void) {
    char expression[100];

    printf("Ingrese una expresion: ");
    fgets(expression, sizeof(expression), stdin);

    size_t length = strlen(expression);
    if (length > 0 && expression[length - 1] == '\n') {
        expression[length - 1] = '\0';
    }

    filterExpression(expression);

    return EXIT_SUCCESS;
}








