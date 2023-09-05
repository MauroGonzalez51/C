#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *nextElement;
} Node;

typedef struct LinkedList {
    int size;
    Node *head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList *list = (LinkedList *) malloc (sizeof(LinkedList));

    if (!list) { return NULL; }

    list -> size = 0;
    list -> head = NULL;
    return list;
}

void insertAtBeginning(LinkedList *list, int value) {
    Node *newNode = (Node *) malloc (sizeof(Node));

    if (!newNode) { return; }

    // * HERE is where the values get assigned

    newNode -> value = value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = list -> head;
    list -> head = newNode;
    list->size++;
}

void insertAtEnd(LinkedList *list, int value) {
    Node *newNode = (Node *) malloc (sizeof(Node));

    if (!newNode) { return; }

    // * HERE is where the values get assigned

    newNode -> value = value;

    // * ------------------------------------------------------|>

    newNode -> nextElement = NULL;
    
    if (list -> head == NULL) {
        list -> head = newNode;
    } else {
        Node *current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }
        current -> nextElement = newNode;
    }
    
    list -> size++;
}

void deleteElement(LinkedList *list, int value) {
    if (list -> head == NULL) { return; }


    // * HERE 

    if (list -> head -> value == value) {
        Node *temp = list -> head;
        list -> head = list -> head -> nextElement;
        free(temp);
        list->size--;
        return;
    }

    // * ------------------------------------------------------|>

    // * HERE

    Node *current = list -> head;
    while (current -> nextElement != NULL && current -> nextElement -> value != value) {
        current = current -> nextElement;
    }

    // * ------------------------------------------------------|>

    if (current -> nextElement == NULL) { return; }

    Node *temp = current -> nextElement;
    current -> nextElement = temp -> nextElement;
    free(temp);
    list->size--;
}

int search(LinkedList *list, int value) {
    Node *current = list -> head;
    int index = 0;

    // * HERE

    while (current != NULL) {
        if (current -> value == value) { return index; }
        current = current -> nextElement;
        index++;
    }

    // * ------------------------------------------------------|>

    return -1; 
}

void printLinkedList(LinkedList *list) {
    Node *current = list -> head;
    while (current != NULL) {
        printf("%d -> ", current -> value);
        current = current -> nextElement;
    }
    printf("NULL\n");
}

void freeLinkedList(LinkedList *list) {
    Node *current = list -> head;
    while (current != NULL) {
        Node *temp = current;
        current = current -> nextElement;
        free(temp);
    }
    free(list);
}

Node* getElementByIndex(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) { return NULL; }

    Node *current = list -> head;
    int currentIndex = 0;

    while (current != NULL && currentIndex != index) {
        current = current->nextElement;
        currentIndex++;
    }

    return current;
}


int main() {
    LinkedList *list = createLinkedList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtBeginning(list, 5);

    printf("Lista actual: ");
    printLinkedList(list);

    int searchValue = 20;
    int index = search(list, searchValue);
    if (index != -1) {
        printf("%d se encuentra en el índice %d.\n", searchValue, index);
    } else {
        printf("%d no se encuentra en la lista.\n", searchValue);
    }

    deleteElement(list, 20);

    printf("Lista después de eliminar 20: ");
    printLinkedList(list);

    freeLinkedList(list);

    return EXIT_SUCCESS;
}
