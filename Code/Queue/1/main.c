#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

void invertOrder(Queue *queue, Stack *stack) {

}

int main(void) {
    Queue queue;
    Stack auxiliarStack;

    createQueue(&queue);
    createStack(&auxiliarStack);

    printf("Elementos de la cola: ");
    for (int i = 0; i < 10; i++) {
        Node node;
        node.value = i;
        enQueue(&queue, node);
        printf("Agregando valor: %d\n", node.value);
    }

    invertOrder(&queue, &auxiliarStack);

    return EXIT_SUCCESS;
}