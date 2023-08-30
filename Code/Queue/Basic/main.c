#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void) {
    Queue queue;

    createQueue(&queue);

    for (int i = 0; i < 10; i++) {
        Node node;
        node.value = i;
        enQueue(&queue, node);
    }

    displayQueue(&queue);

    printf("Size: %d\n", queue.size);

    return EXIT_SUCCESS;
}