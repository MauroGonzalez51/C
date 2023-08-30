#include "queue.h"

int createQueue(Queue *queue) {
    queue -> front = NULL;
    queue -> rear = NULL;
    queue -> size = 0;

    return 1;
}

int enQueue(Queue *queue, Node node) {
    Node *newElement = (Node *) malloc (sizeof(Node));

    if (newElement == NULL) { return 0; }


    // * ---------------------------------------------------------------------|>

    // ! Here is where the properties are asigned
    newElement -> value = node.value;

    // * ---------------------------------------------------------------------|>

    if (queue -> front == NULL) {
        queue -> front = newElement;
        queue -> rear = newElement;
    } else {
        queue -> rear -> nextElement = newElement;
        queue -> rear = queue -> rear -> nextElement;
    }

    return 1;
}

Node* deQueue(Queue *queue) {
    if (queue -> front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    Node *element = queue -> front;
    queue -> front = queue -> front -> nextElement;
    return element;
}

void displayQueue(Queue *queue) {
    Queue *cpy = queue;
    
    while (queue -> front != NULL) {
        Node* element = deQueue(queue);
        printf("%d\n", element -> value);
    }
}