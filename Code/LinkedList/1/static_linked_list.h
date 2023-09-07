#ifndef STATIC_LINKED_LIST_H
#define STATIC_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "static_node.h"
#include "functions.h"

typedef struct StaticLinkedList {
    int maxSize;
    int currentSize;
    StaticNode *head;

    // * Properties of the course

    char* courseName, *ID;

    // * ---------------------------------------|>

} StaticLinkedList;

StaticLinkedList* createStaticLinkedList(int maxSize);
int isListFull(StaticLinkedList *list);
int insertAtEnd(StaticLinkedList *list, StaticNode node);

#endif