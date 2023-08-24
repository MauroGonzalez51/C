#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "stack.h" 
#include "functions.h"

int main() {
    char expression[100];

    printf("Ingrese una expresion postfija: ");
    scanf("%s", expression);

    evaluatePostfix(expression);

    return 0;
}

