#ifndef NODE_H
#define NODE_H

// * Basically is StudentNode but to keep it simple just Node :D

typedef struct Node {
    char *studentName, *ID, *noIdentification, *email;
    struct Node *nextElement;
} StaticNode;

#endif
