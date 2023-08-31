#ifndef STACK_H
#define STACK_H

#include "node.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Node *top;
    int size;
} Stack;

void createStack(Stack *stack);
void push(Stack *stack, char value);
Node* pop(Stack *stack);
int isEmptyStack(Stack *stack);

#endif