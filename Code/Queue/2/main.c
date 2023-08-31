#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    Queue queue;

    createQueue(&queue);

    char input[100];

    printf("Ingrese una cadena: ");
    scanf("%s", &input);

    for (int i = 0; i < strlen(input); i++) {
        enQueue(&queue, input[i]);
    }

    printf("Original: ");

    printQueue(&queue);

    return EXIT_SUCCESS;
}
