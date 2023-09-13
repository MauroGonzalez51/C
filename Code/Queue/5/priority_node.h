#ifndef PRIORITY_NODE
#define PRIORITY_NODE

#include "element.h"

typedef struct PriorityNode {
    Element element;
    struct PriorityNode *next;
} PriorityNode;

#endif