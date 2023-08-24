#ifndef STACKMETHODSH
#define STACKMETHODS_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "element.h"

int createStack(Stack *stack);
int push(Stack *stack, Element element);
Element* pop(Stack *stack);
int size(Stack *stack);

#endif