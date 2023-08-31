#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char *userName;
    int pageSize, printTime;
    struct Node *nextElement;
} Node;

#endif