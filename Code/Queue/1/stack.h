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
void push(Stack *stack, int value);
int pop(Stack *stack);
int isEmptyStack(Stack *stack);

#endif