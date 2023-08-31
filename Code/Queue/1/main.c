#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"

#define MAX_ELEMENTS 10

void reverseQueue(Queue *queue);

int main() {
    Queue queue;
    createQueue(&queue);

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        enQueue(&queue, i + 1);
    }

    printf("Original queue: ");

    printQueue(&queue);

    printf("\n");

    reverseQueue(&queue);

    printf("Reversed queue: ");
    
    printQueue(&queue);

    printf("\n");

    return 0;
}

void reverseQueue(Queue *queue) {
    Stack stack;
    createStack(&stack);

    while (!isEmptyQueue(queue)) {
        Node *element = deQueue(queue);
        push(&stack, element->value);
        free(element);
    }

    while (!isEmptyStack(&stack)) {
        int value = pop(&stack);
        enQueue(queue, value);
    }
}
