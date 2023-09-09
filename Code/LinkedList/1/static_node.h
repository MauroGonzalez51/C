#ifndef STATIC_NODE_H
#define STATIC_NODE_H

typedef struct StaticNode {
    char *studentName, *ID, *noIdentification, *email;
    float finalGrade;
    struct StaticNode *nextElement;
} StaticNode;

#endif
