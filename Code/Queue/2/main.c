#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

int isQueuePalindrome(Queue *queue) {
    Stack stack;
    createStack(&stack);

    Node *current = queue -> front;

    while (current != NULL) {
        push(&stack, current -> value);
        current = current -> nextElement;
    }

    current = queue->front;
    while (current != NULL) {
        Node* stackValue = pop(&stack);

        // ! Making comparissons between the first and last element till reaching center

        if (current->value != stackValue -> value) {
            return 0; 
        }
        current = current->nextElement;
    }

    return 1; 
}

int main() {
    Queue queue;

    createQueue(&queue);

    char input[100];

    printf("Ingrese una cadena: ");
    scanf("%s", &input);

    for (int i = 0; i < strlen(input); i++) {
        enQueue(&queue, input[i]);
    }

    printf("\n");

    printf("Original: ");

    printQueue(&queue);

    printf("\n");

    (isQueuePalindrome(&queue)) ?
        printf("La cola es Palindroma\n") :
        printf("La cola no es Palindroma\n");

    return EXIT_SUCCESS;
}
