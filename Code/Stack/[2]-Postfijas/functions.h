#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack.h"

float calcule(char operation, float a, float b);
int isdigit(char element);
int isOperator(char element);
void evaluatePostfix(char *expression);

#endif