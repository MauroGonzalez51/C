#include "stack.h"
#include "element.h"

int createStack(Stack *stack) {
    stack->front = NULL;
    stack->size = 0;
    return 1;
}

int push(Stack *stack, Element element) {
    Element *newElement = (Element *)malloc(sizeof(Element)); 

    if (newElement == NULL) {
        return 0;
    }

    newElement -> item = element.item;
    
    newElement -> nextElement = stack -> front;

    stack -> front = newElement;
    stack -> size++;

    return 1;
}

Element* pop(Stack *stack) {
    if (stack->front == NULL) {
        return NULL;
    }

    Element *poppedElement = stack->front;
    stack -> front = poppedElement->nextElement;
    stack -> size--;

    return poppedElement;
}

int size(Stack *stack) {
    return stack->size;
}

int isEmpty(Stack *stack) {
    return stack -> size == 0;
}