#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node *node = (Node *) malloc(sizeof(Node));

    if (!node) { return NULL; }

    node -> left = node -> right = NULL;
    node -> value = value;
    return node;
}

void insertNode(Node *node, int value) {
    if (value > node -> value) {
        // * Insert in [ RIGHT ]
        if (node -> right == NULL) {
            node -> right = createNode(value);
        } else { insertNode(node -> right, value); }
    } else {
        // * Insert in [ LEFT ]
        if (node -> left == NULL) {
            node -> left = createNode(value);
        } else { insertNode(node -> left, value); }
    }
}

void preOrden(Node *node) {
    if (node != NULL) {
        printf("%d, ", node -> value);
        preOrden(node -> left);
        preOrden(node -> right);
    }
}

void inOrden(Node *node) {
    if (node != NULL) {
        inOrden(node -> left);
        printf("%d, ", node -> value);
        inOrden(node -> right);
    }
}




int main() {
    Node *node = createNode(52);
    return EXIT_SUCCESS;
}