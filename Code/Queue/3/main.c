#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 20

#include "queue.h"

Queue* concatenateQueue(Queue *q1, Queue *q2) {
    Queue *result = (Queue *) malloc (sizeof(Queue));
    createQueue(result);

    while (q1->front != NULL) {
        Node *n = deQueue(q1);
        enQueue(result, n->value);
        free(n);
    }

    while (q2->front != NULL) {
        Node *n = deQueue(q2);
        enQueue(result, n->value);
        free(n);
    }

    return result;
}

int main() {
    Queue q1, q2;
    createQueue(&q1);
    createQueue(&q2);

    // * Filling the queue's

    for (int i = 0; i < MAX_ELEMENTS / 2; i++) {
        enQueue(&q1, i);
    }

    for (int i = MAX_ELEMENTS / 2; i < MAX_ELEMENTS; i++) {
        enQueue(&q2, i);
    }

    printf("Queue [1]: ");
    printQueue(&q1);

    printf("Queue [2]: ");
    printQueue(&q2);

    printf("\n");

    Queue *concatenatedQueue = concatenateQueue(&q1, &q2);

    printf("Result: ");
    printQueue(concatenatedQueue);

    return EXIT_SUCCESS;
}