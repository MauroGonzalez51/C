#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "circular_queue.h"

#define CAPACITY 8

int main() {
    srand(time(NULL));

    CircularQueue *queue = createCircularQueue(CAPACITY);

    for (int i = 0; i < CAPACITY; i++) {
        printf("Agregando %d\n", i);
        enQueue(queue, i);
    }

    printf("\n\n");

    printf("Elemento al frente de la cola: %d\n", front(queue));

    int nElementsToEliminate = rand() % CAPACITY + 1;

    for (int i = 0; i < nElementsToEliminate; i++) {
        deQueue(queue);
    }

    printf("\n\n");

    printf("Elemento al frente de la cola despues de %d eliminaciones: %d\n", nElementsToEliminate,front(queue));

    printf("\n\n");
    if (!isEmpty(queue)) {
        printf("Elementos restantes \n\n");
        while (!isEmpty(queue)) {
            printf("Elemento desencolado: %d\n", deQueue(queue));
        }
    }

    freeCircularQueue(queue);

    return EXIT_SUCCESS;
}
