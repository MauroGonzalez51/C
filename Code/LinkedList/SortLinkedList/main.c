#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *nextElement;
} DynamicNode;

typedef struct LinkedList {
    int size;
    DynamicNode *head;
} DynamicLinkedList;

DynamicLinkedList* createDynamicLinkedList() {
    DynamicLinkedList *list = (DynamicLinkedList *) malloc(sizeof(DynamicLinkedList));

    if (!list) { return NULL; }

    list -> head = NULL;
    list -> size = 0;
    return list;
}

int insertAtEnd(DynamicLinkedList *list, DynamicNode node) {
    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));

    if (!newNode) { return 0; }

    newNode -> value = node.value;

    newNode -> nextElement = NULL;

    if (list -> head == NULL) {
        list -> head = newNode;
    } else {
        DynamicNode *current = list -> head;
        while (current -> nextElement != NULL) {
            current = current -> nextElement;
        }

        current -> nextElement = newNode;
    }

    list -> size++;
    return 1;
} 

int insertWhileKeeppingSorted(DynamicLinkedList *list, DynamicNode node) {
    DynamicNode *newNode = (DynamicNode *) malloc(sizeof(DynamicNode));

    if (!newNode) return 0;

    newNode -> value = node.value;

    DynamicNode *current, *next;

    current = list -> head;
    next = (current != NULL) ? current -> nextElement : NULL;

    while (next != NULL) {
        // * Verificar si el list -> head tiene un valor mayor al newNode
        // * En caso de que sea asi, significa de que se debe insertar al principio
        // * Se termina la funcion con el return 1, asi no se hacen mas comparacines

        if (newNode -> value < current -> value) {
            newNode -> nextElement = current;
            list -> head = newNode;
            return 1;
        }

        // * El nuevo nodo debe de estar entre dos nodos diferentes
        // * Debe ser mayor al current pero menor al siguiente
        // * Se inserta mediante asignacion de punteros
        // * Se termina la funcion con el return 1;

        if (
            ((newNode -> value > current -> value) || (newNode -> value == current -> value)) && 
            (newNode -> value < next -> value)
        ) {
            current -> nextElement = newNode;
            newNode -> nextElement = next;
            return 1;
        }

        current = next;
        next = current -> nextElement;
    }

    // * Luego cuando el while se termine, osea que el valor es mayor a todos los que
    // * estan en la lista, eso quiere decir que se va a insertar al final
    // * para eso se utiliza la funcion insertAtEnd()

    return insertAtEnd(list, node);
}

int deleteWhileKeeppingSorted(DynamicLinkedList *list, DynamicNode node) {
    if (!list -> head) return 0;
    
    DynamicNode *previous, *current, *next;

    previous = NULL;
    current = list -> head;
    next = (current != NULL) ? current -> nextElement : NULL;

    // * Recorrer la list hasta llegar al final
    // * Debido al next != NULL, no se llega a verificar el ultimo elemento

    while (next != NULL) {

        // * En caso de que sean iguales se debe eliminar

        if (current -> value == node.value) {

            // * Si previous == NULL, significa que se esta en el comienzo
            // * de la lista, entonces se debe re-asginar list -> head

            if (previous != NULL) previous -> nextElement = next;
            else list -> head = next;
            
            free(current);
            return 1;
        }

        // * Avanzando en la lista

        previous = current;
        current = previous -> nextElement;
        next = current -> nextElement;
    }

    // * Revisando el ultimo elemento
    
    if (current -> value == node.value) {
        if (previous != NULL) previous -> nextElement = NULL;
        else list -> head = NULL;

        free(current);
        return 1;
    }

    // * Si el valor no se encuentra en la lista
    // * simplemente se retorna 0

    return 0;
}

void sortList(DynamicLinkedList *list) {
    DynamicNode *previous, *current, *next;

    if (list -> size <= 1) { return; }

    int swapped;

    do {
        // * En el ordenamiento burbuja de normal se tiene un ciclo dentro de otro
        // * Uno es para gestionar los movimientos del elemento, 1 iteracion = 1 movimiento
        // * Luego, la "outer iteration" es para gestionar cada elemento
        // * Asi se asegura de que la lista este ordenada

        swapped = 0;

        previous = NULL;
        current = list -> head;
        next = current -> nextElement;

        // * Se va a ejecutar esto hasta que next != NULL, es decir hasta que se llegue
        // * al final de la lista

        while (next != NULL) {

            // * En caso de que current -> value > next -> value, se deben intercambiar
            // * .momentoDibujo();
            // * el caso de previous == NULL, significa que estamos en el inicio de la lista
            // * Asi que el list -> head debe reasignarse

            if (current -> value > next -> value) {
                if (previous != NULL) previous -> nextElement = next;
                else list -> head = next;

                // * .momentoDibujo();

                current -> nextElement = next -> nextElement;
                next -> nextElement = current;

                // * Variable de control para que el ciclo siga o no

                swapped = 1;
            }

            // * Avanzar en la lista mediante el uso de punteros

            previous = current;
            current = next;
            next = current->nextElement;
        }
    } while (swapped);
}

DynamicNode* searchElementInList(DynamicLinkedList* list, DynamicNode node) {
    if (!list -> head) { return NULL; }

    DynamicNode *current = list -> head;
    while (current != NULL) {
        if (current -> value == node.value) break;
        current = current -> nextElement;
    }

    return current;
}

int getIndexOfElement(DynamicLinkedList* list, DynamicNode node) {
    int index = 0;
    DynamicNode *current = list -> head;
    while (current != NULL) {
        if (current -> value == node.value) return index;

        index++;
        current = current -> nextElement;
    }

    return index;
}

void printList(DynamicLinkedList *list, int oneline) {
    if (oneline) {
        DynamicNode *current = list -> head;
        while (current -> nextElement != NULL) {
            printf("%d ", current -> value);
            current = current -> nextElement;
        }

        printf("%d\n", current -> value);
        return;
    }

    DynamicNode *current = list -> head;
    while (current != NULL) {
        printf("%d\n", current -> value);
        current = current -> nextElement;
    }
}

int listsAreEqual(DynamicLinkedList *list1, DynamicLinkedList *list2) {
    if (list1 == NULL || list2 == NULL) { return 0; }
    if (list1 -> size != list2 -> size) { return 0; }

    // * Si llega aqui significa de que el tamaño de las listas es el mismo

    DynamicNode *current1 = list1 -> head;
    DynamicNode *current2 = list2 -> head; 

    // * Pero solo por si acaso, se verifica que ambos sean diferente de NULL;

    while (current1 != NULL && current2 != NULL) {
        
        // * En caso de que algun valor sea diferente, se termina la funcion enseguida

        if (current1 -> value != current2 -> value) return 0;

        current1 = current1 -> nextElement;
        current2 = current2 -> nextElement;
    }

    // * Si se recorre toda la lista y no se termina la funcion
    // * Quiere decir que las listas son iguales

    return 1;
}

int listsAreSimilar(DynamicLinkedList *list, DynamicLinkedList *flag) {

    // * En este caso se verifica si list contiene a flag
    // * Por eso el orden de los Argumentos de la funcion

    DynamicNode *current = flag -> head;
    while (current != NULL) {
        DynamicNode *nodeInList = searchElementInList(list, *current);

        if (!nodeInList) { return 0; }

        current = current -> nextElement;
    }

    return 1;
}

int listsAreSublist(DynamicLinkedList *list, DynamicLinkedList *flag) {
    if (list == NULL || flag == NULL) { return 0; }

    int listPreviousIndex, listNextIndex, listIndexExpected;

    DynamicNode *current = flag->head;
    while (current -> nextElement != NULL) {
        listPreviousIndex = getIndexOfElement(list, *(searchElementInList(list, *current)));

        if (!listPreviousIndex) { return 0; }

        listIndexExpected = listPreviousIndex + 1;

        listNextIndex = getIndexOfElement(list, *(searchElementInList(list, *(current->nextElement))));

        if (!listNextIndex) { return 0; }

        if (listIndexExpected != listNextIndex) { return 0; }

        current = current -> nextElement;
    }

    return 1;
}

int main() {
    DynamicLinkedList *list = createDynamicLinkedList();
    DynamicNode node;

    int elements[] = {1, 15, 3, 2, 7, 4, 9, 5};
    int size = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < size; i++) {
        node.value = elements[i];
        if (!insertAtEnd(list, node)) exit(EXIT_FAILURE);
    }

    printf("\nInitial list: \n");
    printList(list, 1);


    printf("\nSorted list: \n");
    sortList(list);
    printList(list, 1);

    printf("\nList after adding [ node.value = 20 ]: \n");
    node.value = 20;
    insertWhileKeeppingSorted(list, node);
    printList(list, 1);

    printf("\nInsert a value to be searched in the list: ");
    scanf("%d", &node.value);
    DynamicNode *elementFound = searchElementInList(list, node);
    (elementFound) ? printf("\nElement found: %d\n", elementFound -> value) :
    printf("\nThe element [%d] is not in the list\n", node.value);

    printf("\nRemove a node [ node.value = 7 ]: \n");
    node.value = 7;
    deleteWhileKeeppingSorted(list, node); 
    printList(list, 1);

    printf("\nAdd a new node [ node.value = 6 ]: \n");
    node.value = 6;
    insertWhileKeeppingSorted(list, node);
    printList(list, 1);

    // * Arroja segmentation fault :D

    // DynamicLinkedList *newList = createDynamicLinkedList();
    // int newElements[] = {1, 2, 3}; 
    // int newSize = sizeof(newElements) / sizeof(newElements[0]);

    // for (int i = 0; i < newSize; i++) {
    //     node.value = newElements[i];
    //     if (!insertAtEnd(list, node)) exit(EXIT_FAILURE);
    // }

    // sortList(newList);

    // if (listsAreSublist(list, newList)) { printf("true\n"); }
    // else printf("false\n");
    
    return EXIT_SUCCESS;
}