#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include "priority_node.h"
#include "element.h"

typedef struct {
    PriorityNode *front;
} PriorityQueue;

PriorityQueue *createPriorityQueue();
void enQueue(PriorityQueue *queue, Element element);
PriorityNode* deQueue(PriorityQueue *queue);
int peek(PriorityQueue *queue);
void freePriorityQueue(PriorityQueue *queue);

#endif