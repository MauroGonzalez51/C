#include "circular_queue.h"

CircularQueue* createCircularQueue(int capacity) {
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!queue) {
        return NULL;  
    }

    queue -> data = (int *)malloc(capacity * sizeof(int));
    if (!queue -> data) {
        free(queue);
        return NULL; 
    }

    queue -> front = -1;
    queue -> rear = -1;
    queue -> size = 0;
    queue -> capacity = capacity;

    return queue;
}

int isEmpty(CircularQueue *queue) {
    return queue -> size == 0;
}

int isFull(CircularQueue *queue) {
    return queue -> size == queue -> capacity;
}

void enQueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("La cola esta llena\n");
        return;
    }

    if (isEmpty(queue)) {
        queue -> front = 0;
        queue -> rear = 0;
    } else {
        queue -> rear = (queue -> rear + 1) % queue->capacity;
    }

    queue -> data[queue->rear] = value;
    queue -> size++;
}

int deQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("La cola esta vacia\n");
        return -1;
    }

    int value = queue -> data[queue -> front];
    if (queue -> front == queue -> rear) {
        queue -> front = -1;
        queue -> rear = -1;
    } else {
        queue -> front = (queue->front + 1) % queue -> capacity;
    }

    queue -> size--;
    return value;
}

int front(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("La cola esta vacia\n");
        return -1; 
    }

    return queue -> data[queue->front];
}

void freeCircularQueue(CircularQueue *queue) {
    if (queue) {
        if (queue->data) {
            free(queue->data);
        }
        free(queue);
    }
}