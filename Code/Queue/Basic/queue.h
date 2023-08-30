#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "node.h"

typedef struct Queue {
    Node *front;
    Node *rear;
    unsigned int size;
} Queue;

int createQueue(Queue *queue);
int enQueue(Queue *queue, Node node);
Node* deQueue(Queue *queue);
void displayQueue(Queue *queue);

#endif