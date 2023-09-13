#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "priority_queue.h"

#define MAX_ELEMENTS 10

int main() {
    srand(time(NULL));

    PriorityQueue *queue = createPriorityQueue();

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        Element element;
        element.value = i;
        element.priority = rand() % 100;
        printf("Value: %d | Priority: %f\n", element.value, element.priority);
        enQueue(queue, element);
    }

    printf("\n");

    printf("Elemento con mayor prioridad: %d (Value)\n", peek(queue));

    printf("\nElementos ordenados por prioridad: \n");

    while (queue -> front != NULL) {
        PriorityNode *node = deQueue(queue);
        printf("\nValue: %d | Priority: %f", node -> element.value, node -> element.priority);
    }

    printf("\n");

    freePriorityQueue(queue);

    return EXIT_SUCCESS;
}
