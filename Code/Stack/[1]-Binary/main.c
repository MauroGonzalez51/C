#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "functions.h"

int main() {
    int numberToConvert;

    do {
        printf("Ingrese el numero para convertir a binario [POSITIVO]: ");
        scanf("%d", &numberToConvert);  
    } while (numberToConvert <= 0);

    Stack stack;
    createStack(&stack);
    binaryRepresentation(&stack, numberToConvert);
    printStack(&stack);

    return EXIT_SUCCESS;
}
