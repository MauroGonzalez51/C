#include "static_linked_list.h"

StaticLinkedList* createStaticLinkedList(int maxSize) {
    StaticLinkedList* list = (StaticLinkedList *) malloc (sizeof(StaticLinkedList));

    if (!list) { return NULL; }

    list -> maxSize = maxSize;
    list -> currentSize = 0;
    list -> head = NULL;

    return list;
}

int isListFull(StaticLinkedList *list) {
    return list -> currentSize == list -> maxSize;
}

int isEmpty(StaticLinkedList *list) {
    return list -> currentSize == 0;
}

int insertAtEnd(StaticLinkedList *list, StaticNode node) {
    StaticNode* newNode = (StaticNode *) malloc (sizeof(StaticNode));

    if (!newNode) { 
        printf("Error: Failed to allocate");
        return 0; 
    }

    if (isListFull(list)) { 
        log("La lista esta llena");
        return 0; 
    }

    // * HERE is where the values get assigned

    newNode -> studentName = copyString(node.studentName);
    newNode -> ID = copyString(node.ID);
    newNode -> noIdentification = copyString(node.noIdentification);
    newNode -> email = copyString(node.email);
    newNode -> finalGrade = rand() % 6;
    
    // * ------------------------------------------------------|>

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        list -> head = newNode;
    } else {
        StaticNode* current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }

        current -> nextElement = newNode;
    }

    list -> currentSize++;

    return 1;
}