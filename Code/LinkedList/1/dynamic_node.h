#ifndef DYNAMIC_NODE_H
#define DYNAMIC_NODE_H

#include "static_linked_list.h"

typedef struct DynamicNode {
    StaticLinkedList *list;
    struct DynamicNode *nextElement;
} DynamicNode;

#endif