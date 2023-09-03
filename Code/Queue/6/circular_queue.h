#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createCircularQueue(int capacity);
int isEmpty(CircularQueue *queue);
int isFull(CircularQueue *queue);
void enQueue(CircularQueue *queue, int value);
int deQueue(CircularQueue *queue);
int front(CircularQueue *queue);
void freeCircularQueue(CircularQueue *queue);

#endif