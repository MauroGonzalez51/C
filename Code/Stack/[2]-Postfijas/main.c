#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "element.h"

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main(void) {
    char expresion[100];

    printf("Ingrese una expresion: ");
    scanf("%s", expresion);

    Stack stack;

    createStack(&stack);

    
    

    return EXIT_SUCCESS;
}
