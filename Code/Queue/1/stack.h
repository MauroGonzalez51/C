#ifndef STACK_H
#define STACK_H

#include "element.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    Element *front;
    unsigned int size;
} Stack;

int createStack(Stack *stack);
int push(Stack *stack, Element element);
Element* pop(Stack *stack);
int size(Stack *stack);
int isEmpty(Stack *stack);

#endif