#include <stdio.h>
#include <stdlib.h>

typedef struct StaticNode {
    int value;

    StaticNode *nextElement, *prevElement;
} StaticNode;

typedef struct StaticDoubleLinkedList {
    int currentSize, maxSize;
    StaticNode *head;
} StaticDoubleLinkedList;

StaticDoubleLinkedList *createStaticDoubleLinkedList(int maxSize) {
    StaticDoubleLinkedList *list = (StaticDoubleLinkedList *) malloc(sizeof(StaticDoubleLinkedList));

    if (!list) { return; }

    list -> maxSize = maxSize;
    list -> currentSize = 0;
    list -> head = NULL;

    return list;
}

int isListFull(StaticDoubleLinkedList *list) {
    return list -> currentSize == list -> maxSize;
}

int isEmpty(StaticDoubleLinkedList *list) {
    return list -> currentSize == 0;
}

int insertAtBeginning(StaticDoubleLinkedList *list, StaticNode node) {
    StaticNode *newNode = (StaticNode *) malloc(sizeof(StaticNode));

    if (!newNode) { return 0; }

    if (isListFull(list)) { return 0; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = list -> head;
    newNode -> prevElement = NULL;

    if (list -> head) {
        list -> head -> prevElement = newNode;
    }

    list -> head = newNode;
    list -> currentSize++;

    return 1;
}

int insertAtEnd(StaticDoubleLinkedList *list, StaticNode node) {
    StaticNode *newNode = (StaticNode *) malloc(sizeof(StaticNode));

    if (!newNode) { return 0; }

    if (isListFull(list)) { return 0; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        newNode -> prevElement = NULL;
        list -> head = newNode;
    } else {
        StaticNode *current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }

        current -> nextElement = newNode;
        newNode -> prevElement = current;
    }

    list -> currentSize++;
    return 1;
}

int insertAtIndex(StaticDoubleLinkedList *list, StaticNode node, int index) {
    if (index < 0 || index > list -> currentSize) { return 0; }

    StaticNode *newNode = (StaticNode *) malloc(sizeof(StaticNode));
    if (!newNode) { return 0; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    if (index == 0) {
        newNode -> nextElement = list -> head;
        newNode -> prevElement = NULL;
        if (list -> head) {
            list -> head -> prevElement = newNode;
        }
        list -> head = newNode;
    } else {
        StaticNode *current = list -> head;
        for (int i = 0; i < index - 1; i++) { current = current -> nextElement; }

        newNode -> nextElement = current -> nextElement;
        newNode -> prevElement = current;
        current -> nextElement = newNode;

        if (newNode -> nextElement) {
            newNode -> nextElement -> prevElement = newNode;
        }
    }

    list -> currentSize++;
    return 1; 
}

StaticNode *getElementByIndex(StaticDoubleLinkedList *list, int index) {
    if (index < 0 || index >= list -> currentSize) { return NULL; }

    StaticNode *current = list -> head;

    for (int i = 0; i < index; i++) { 
        if (current == NULL) { return NULL; } 
        current = current -> nextElement;
    }

    return current;
}

int main(void) {
    return EXIT_SUCCESS;
}