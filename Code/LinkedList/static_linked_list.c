#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    Node *nextElement;
} Node;

typedef struct StaticLinkedList {
    int maxSize;
    int currentSize;
    Node *head;
} StaticLinkedList;

StaticLinkedList* createStaticLinkedList(int maxSize) {
    StaticLinkedList* list = (StaticLinkedList *) malloc (sizeof(StaticLinkedList));

    if (!list) { return NULL; }

    list -> maxSize = maxSize;
    list -> currentSize = 0;
    list -> head = NULL;

    return list;
}

int isListFull(StaticLinkedList *list) {
    return list -> currentSize == list -> maxSize;
}

void insertAtBeginning(StaticLinkedList *list, Node node) {
    Node* newNode = (Node *) malloc (sizeof(Node));

    if (!newNode) { return; }

    if (isListFull(list)) { return; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = list -> head;
    list -> head = newNode;
    list -> currentSize++;
}

void insertAtEnd(StaticLinkedList *list, Node node) {
    Node* newNode = (Node *) malloc (sizeof(Node));

    if (!newNode) { return; }

    if (isListFull(list)) { return; }

    // * HERE is where the values get assigned

    newNode -> value = node.value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        list -> head = newNode;
    } else {
        Node* current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }

        current -> nextElement = newNode;
    }

    list -> currentSize++;
}

int main(void) {
    return EXIT_SUCCESS;
}