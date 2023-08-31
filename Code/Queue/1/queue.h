#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

void createQueue(Queue *queue);
void enQueue(Queue *queue, int value);
Node* deQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
void printQueue(Queue *queue);

#endif