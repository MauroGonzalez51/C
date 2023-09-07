#ifndef DYNAMIC_LINKED_LIST_H
#define DYNAMIC_LINKED_LIST_H

#include "static_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_node.h"
#include "functions.h"

typedef struct DynamicLinkedList {
    int size;
    DynamicNode *head;
} DynamicLinkedList;

DynamicLinkedList* createDynamicLinkedList();
int insertInList(DynamicLinkedList *list, StaticLinkedList *staticList);
DynamicNode* getElementByIndex(DynamicLinkedList *list, int index);

#endif