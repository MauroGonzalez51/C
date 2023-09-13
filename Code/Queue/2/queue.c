#include "queue.h"

void createQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enQueue(Queue *queue, char value) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->value = value;
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
        printf("%c | ", current -> value);
        current = current -> nextElement;
    }
    printf("\n");
}