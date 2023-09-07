#ifndef NODE_H
#define NODE_H

// * Basically is StudentNode but to keep it simple just Node :D

typedef struct Node {
    int value;
    char *studentName, *ID, *noIdentification, *email;
    Node *nextElement;
} Node;

#endif
