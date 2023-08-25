#include "functions.h"

int precedenceLevel(char operation) {
    int level = 0;

    switch (operation) {
        case '(': 
            level = 0; 
            break;
        case '+': 
            level = 1; 
            break;
        case '-': 
            level = 1; 
            break;
        case '*': 
            level = 2; 
            break;
        case '/': 
            level = 2; 
            break;
        case '$': 
            level = 3; 
            break;
    }

    return level;
}

int hasHigherOrder(char operation1, char operation2) {
    int precedenceLevel1 = precedenceLevel(operation1);
    int precedenceLevel2 = precedenceLevel(operation2);

    return (precedenceLevel1 >= precedenceLevel2);
}

int isOperation(char operation) {
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '$');
}

int isdigit(char element) {
    return (element >= '0' && element <= '9');
}

char* infixToPostfix(char *infix) {
    char element, operation;
    char *postfix = (char *) malloc(strlen(infix) * sizeof(char));

    int j = 0, i = 0;

    Stack stack;
    createStack(&stack);

    int length = strlen(infix);

    while (i < length) {
        element = infix[i];
        i++;

        if (isdigit(element)) {
            postfix[j] = element;
            j++;
        } else if (isOperation(element)) {
            if (!isEmpty(&stack)) {
                int shouldContinue;

                do {
                    Element *e = pop(&stack);
                    operation = e -> item;

                    if (hasHigherOrder(operation, element)) {
                        postfix[j] = operation;
                        j++;
                        shouldContinue = 1;
                    } else {
                        shouldContinue = 0;

                        Element e;
                        e.item = operation;
                        push(&stack, e);
                    }
                } while (!isEmpty(&stack) && shouldContinue);
            }

            Element e;
            e.item = element;
            push(&stack, e);
        } else if (element == '(') {
            Element e;
            e.item = element;
            push(&stack, e);
        } else if (element == ')') {
            Element *e = pop(&stack);
            operation = e -> item;

            while (!isEmpty(&stack) && operation != '(') {
                postfix[j] = operation;
                j++;
                Element *e = pop(&stack);
                operation = e -> item;
            }
        }
    }

    while (!isEmpty(&stack)) {
        Element *e = pop(&stack);
        operation = e -> item;
        postfix[j] = operation;
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}