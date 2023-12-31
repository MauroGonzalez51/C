#include "dynamic_linked_list.h"

DynamicLinkedList* createDynamicLinkedList() {
    DynamicLinkedList* list = (DynamicLinkedList*) malloc(sizeof(DynamicLinkedList));

    if (!list) { return NULL; }

    list -> size = 0;
    list -> head = NULL;
    return list;
}

int insertInList(DynamicLinkedList *list, StaticLinkedList *staticList) {
    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));

    if (!newNode) { return 0; }

    newNode -> list = staticList;

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        list -> head = newNode;
    } else {
        DynamicNode *current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }
        current -> nextElement = newNode;
    }

    list -> size++;
    return 1;
}

DynamicNode* getElementByIndex(DynamicLinkedList *list, int index) {
    if (index < 0 || index >= list -> size) { return NULL; }

    DynamicNode *current = list -> head;
    int currentIndex = 0;

    while (current != NULL && currentIndex != index) {
        current = current -> nextElement;
        currentIndex++;
    }

    return current;
}