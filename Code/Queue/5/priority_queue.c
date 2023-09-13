#include "priority_queue.h"

PriorityQueue *createPriorityQueue() {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (queue == NULL) {
        return NULL; 
    }
    queue->front = NULL;
    return queue;
}

void enQueue(PriorityQueue *queue, Element element) {
    PriorityNode *newNode = (PriorityNode *)malloc(sizeof(PriorityNode));
    if (newNode == NULL) {
        return; 
    }
    newNode->element.value = element.value;
    newNode->element.priority = element.priority;
    newNode->next = NULL;

    if (queue->front == NULL || element.priority > queue -> front -> element.priority) {
        newNode -> next = queue -> front;
        queue -> front = newNode;
    } else {
        PriorityNode *current = queue->front;
        while (current -> next != NULL && current -> next -> element.priority >= element.priority) {
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
    }
}

PriorityNode* deQueue(PriorityQueue *queue) {
    if (queue->front == NULL) {
        return NULL; 
    }

    PriorityNode *element = queue -> front;
    queue -> front = queue -> front -> next;

    return element;
}

int peek(PriorityQueue *queue) {
    if (queue -> front == NULL) {
        return -1; 
    }
    return queue -> front -> element.value;
}

void freePriorityQueue(PriorityQueue *queue) {
    while (queue->front != NULL) {
        PriorityNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}