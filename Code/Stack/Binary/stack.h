#include <stdio.h>
#include <stdlib.h>

#define RETURN_SUCCESS 1
#define RETURN_FAILURE 0

typedef struct Element {
    int number;
    
    struct Element *nextElement;
} Element;

typedef struct Stack {
    struct Element *front;
    unsigned int size;
} Stack;

int createStack(Stack *stack) {
    stack -> front = NULL;
    stack -> size = 0;
    return RETURN_SUCCESS;
}

int push(Stack *stack, Element element) {
    Element *newElement = (Element *) malloc(sizeof(Element));

    if (newElement = NULL) { return RETURN_FAILURE; }

    newElement -> number = element.number;
    newElement -> nextElement = stack -> front;

    stack -> front = newElement;
    stack -> size++;

    return RETURN_SUCCESS;
}

Element* pop(Stack *stack) {
    if (stack -> front == NULL) { return NULL; }

    Element *poppedElement = stack -> front;

    stack -> front = poppedElement -> nextElement;
    stack -> size--;

    return poppedElement;
}

int size(Stack *stack) {
    return stack -> size;
}