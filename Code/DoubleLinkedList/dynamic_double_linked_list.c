#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicNode {
    int value;
    DynamicNode *nextElement, *prevElement;
} DynamicNode;

typedef struct DynamicDoubleLinkedList {
    int size;
    DynamicNode *head;
} DynamicDoubleLinkedList;

DynamicDoubleLinkedList *createDynamicDoubleLinkedList() {
    DynamicDoubleLinkedList *list = (DynamicDoubleLinkedList *) malloc(sizeof(DynamicDoubleLinkedList));

    if (!list) { return; }

    list -> head = NULL;
    list -> size = 0;
    return list;
}

int isEmpty(DynamicDoubleLinkedList *list) {
    return list -> size == 0;
}

int insertAtBeginning(DynamicDoubleLinkedList *list, DynamicNode node) {
    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));

    if (!newNode) { return 0; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = list->head;
    newNode -> prevElement = NULL;

    if (list->head) {
        list->head->prevElement = newNode;
    }

    list -> head = newNode;
    list -> size++;

    return 1;
}

int insertAtEnd(DynamicDoubleLinkedList *list, DynamicNode node) {
    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));

    if (!newNode) { return 0; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        newNode -> prevElement = NULL;
        list -> head = newNode;
    } else {
        DynamicNode *current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }

        current -> nextElement = newNode;
        newNode -> prevElement = current;
    }

    list -> size++;
    return 1;
}

int insertAtIndex(DynamicDoubleLinkedList *list, DynamicNode node, int index) {
    if (index < 0 || index > list -> size) { return 0; }

    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));
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
        DynamicNode *current = list -> head;
        for (int i = 0; i < index - 1; i++) { current = current -> nextElement; }

        newNode -> nextElement = current -> nextElement;
        newNode -> prevElement = current;
        current -> nextElement = newNode;

        if (newNode -> nextElement) {
            newNode -> nextElement -> prevElement = newNode;
        }
    }

    list -> size++;
    return 1; 
}

DynamicNode *getElementByIndex(DynamicDoubleLinkedList *list, int index) {
    if (index < 0 || index > list -> size) { return 0; }

    DynamicNode *current = list -> head;
    
    for (int i = 0; i < index; i++) {
        if (current == NULL) { return NULL; }
        current = current -> nextElement;
    }

    return current;
}

int main() { return EXIT_SUCCESS; }