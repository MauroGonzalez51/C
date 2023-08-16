#include <stdio.h>
#include <malloc.h>

#define EXIT_SUCCESS 0
#define RETURN_SUCCESS 1
#define RETURN_FAILURE 0

struct Element {
    int number;
    struct Element *nextElement;
};

struct Stack {
    struct Element *front;
    unsigned int size;
};

int createStack(struct Stack *);
int push(struct Stack *, struct Element element);

int main(void) {
    struct Stack stack;

    createStack(&stack);

    return 0;
}

int createStack(struct Stack *stack) {
    stack -> front = NULL;
    stack -> size = 0;
    return RETURN_SUCCESS;
}

int push(struct Stack *stack, struct Element element) {
    struct Element newElement = (struct element *) malloc(sizeof(element)); 

    return RETURN_SUCCESS;
}