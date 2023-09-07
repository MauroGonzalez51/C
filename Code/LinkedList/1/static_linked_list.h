#ifndef STATIC_LINKED_LIST_H
#define STATIC_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct StaticLinkedList {
    int maxSize;
    int currentSize;
    Node *head;

    // * Properties of the course

    char* courseName, *ID;

    // * ---------------------------------------|>

} StaticLinkedList;

StaticLinkedList* createStaticLinkedList(int maxSize);
int isListFull(StaticLinkedList *list);
int insertAtBeginning(StaticLinkedList *list, Node node);
int insertAtEnd(StaticLinkedList *list, Node node);

#endif