#ifndef STATIC_NODE_H
#define STATIC_NODE_H

typedef struct StaticNode {
    char *studentName, *ID, *noIdentification, *email;
    struct StaticNode *nextElement;
} StaticNode;

#endif
