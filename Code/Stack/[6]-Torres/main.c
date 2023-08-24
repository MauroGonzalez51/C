#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void solveHanoi(int n, Stack *source, Stack *auxiliary, Stack *destination, int sourceRod, int auxiliaryRod, int destinationRod) {
    if (n == 1) {
        int item = pop(source);
        push(destination, item);
        printf("Mover disco %d de Torre %d a Torre %d\n", item, sourceRod, destinationRod);
        return;
    }

    solveHanoi(n - 1, source, destination, auxiliary, sourceRod, destinationRod, auxiliaryRod);

    int item = pop(source);
    push(destination, item);
    printf("Mover disco %d de Torre %d a Torre %d\n", item, sourceRod, destinationRod);
    solveHanoi(n - 1, auxiliary, source, destination, auxiliaryRod, sourceRod, destinationRod);
}

int main(void) {
    int numDiscos;

    printf("Ingrese la cantidad de discos: ");
    scanf("%d", &numDiscos);

    Stack *source = createStack(numDiscos);
    Stack *auxiliary = createStack(numDiscos);
    Stack *destination = createStack(numDiscos);

    for (int i = 1; i <= numDiscos; i++) {
        push(source, i);
    }

    printf("Pasos para resolver las Torres de Hanoi: \n");

    /**
     * * 1 sourceRod
     * 
     * * 2 auxiliaryRod
     * 
     * * 3 destinationRod
    */

    solveHanoi(numDiscos, source, auxiliary, destination, 1, 2, 3);

    free(source->items);
    free(auxiliary->items);
    free(destination->items);
    free(source);
    free(auxiliary);
    free(destination);

    return EXIT_SUCCESS;
}