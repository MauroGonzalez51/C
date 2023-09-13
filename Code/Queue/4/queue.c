#include "queue.h"

void createQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enQueue(Queue *queue, Node node) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    
    newElement -> userName = (char *) malloc (strlen(node.userName + 1) * sizeof(char));
    strcpy(newElement -> userName, node.userName);

    newElement -> pageSize = node.pageSize;
    newElement -> printTime = rand() % 10 + 1;

    newElement->nextElement = NULL;

    if (isEmptyQueue(queue)) {
        queue->front = newElement;
        queue->rear = newElement;
    } else {
        queue->rear->nextElement = newElement;
        queue->rear = newElement;
    }

    queue->size++;
}


Node* deQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return NULL;
    }

    Node *element = queue->front;
    queue->front = queue->front->nextElement;
    queue->size--;

    return element;
}

int isEmptyQueue(Queue *queue) {
    return queue->size == 0;
}

void printQueue(Queue *queue) {
    Node *current = queue -> front;
    while (current != NULL) {
        for (int i = 0; i < 40; i++) {
            printf("-");
        } 
        printf("\n\n");

        printf("Nombre de usuario: %s\n", current -> userName);       
        printf("Numero de paginas: %d\n", current -> pageSize);
        printf("Tiempo de impresion: %d Segundos\n", current -> printTime);
        printf("\n");

        fflush(stdout); 

        // * It's supposed that the program should stop here for a while
        // * but for some reason seems to not be working :/

        Sleep(current -> printTime);

        current = current -> nextElement;
    }
    printf("\n");
}
