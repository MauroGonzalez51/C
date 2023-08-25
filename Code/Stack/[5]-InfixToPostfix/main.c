#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "functions.h"

int main(void) {
    char expression[100];

    printf("Ingrese una expresion infija: ");
    scanf("%s", &expression);
    
    char *postfix = infixToPostfix(expression);

    printf("%s\n", postfix);

    return EXIT_SUCCESS;
}








