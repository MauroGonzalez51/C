#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct GenericLinkedList {
    struct Node *head;
} GenericLinkedList;

Node *_createNode(void *data) {
    Node *node = (Node *) malloc(sizeof(Node));

    if (!node) return NULL;

    node -> data = data;
    node -> next = NULL;

    return node;
};

GenericLinkedList *init() {
    GenericLinkedList *list = (GenericLinkedList *) malloc(sizeof(GenericLinkedList));

    if (!list) return NULL;

    list -> head = _createNode(NULL);

    return list;
};

Node *pop(GenericLinkedList *list) {
    if (!list -> head || !list -> head -> next) {
        Node *head = list -> head;
        list -> head = NULL;
        return head;
    }

    Node *current = list -> head;
    while (current -> next -> next != NULL)
        current = current -> next;

    Node *node = current -> next;
    current -> next = NULL;
    return node;
}

int add(GenericLinkedList *list, void *data) {
    Node *node = _createNode(data);
    if (!node) return 0;

    if (!list -> head) {
        list -> head = node;
        return 1;
    }

    Node *current = list -> head;
    while (current -> next != NULL)
        current = current -> next;

    current -> next = node;
    return 1;
}

int main(void) {
    GenericLinkedList *numbers = init();
    return 0;
}