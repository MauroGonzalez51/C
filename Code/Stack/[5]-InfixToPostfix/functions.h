#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int precedenceLevel(char operation);
int hasHigherOrder(char operator1, char operator2);
int isOperator(char operation);
int isdigit(char element);
char* infixToPostfix(char *infix);

#endif