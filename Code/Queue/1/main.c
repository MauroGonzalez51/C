#include <stdio.h>
#include <stdlib.h>

// Definición de estructuras
typedef struct Node {
    int value;
    struct Node *nextElement;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

typedef struct {
    Node *top;
    int size;
} Stack;

// Prototipos de funciones
void createQueue(Queue *queue);
void enQueue(Queue *queue, int value);
Node* deQueue(Queue *queue);
int isEmptyQueue(Queue *queue);

void createStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isEmptyStack(Stack *stack);

void reverseQueue(Queue *queue);

int main() {
    Queue queue;
    createQueue(&queue);

    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    enQueue(&queue, 4);
    enQueue(&queue, 5);

    printf("Original queue: ");
    Node *current = queue.front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->nextElement;
    }
    printf("\n");

    reverseQueue(&queue);

    printf("Reversed queue: ");
    current = queue.front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->nextElement;
    }
    printf("\n");

    return 0;
}

// Implementación de funciones
void createQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enQueue(Queue *queue, int value) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->value = value;
    newElement->nextElement = NULL;

    if (isEmptyQueue(queue)) {
        queue->front = newElement;
        queue->rear = newElement;
    } else {
        queue->rear->nextElement = newElement;
        queue->rear = newElement;
    }

    queue->size++;
}

Node* deQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return NULL;
    }

    Node *element = queue->front;
    queue->front = queue->front->nextElement;
    queue->size--;

    return element;
}

int isEmptyQueue(Queue *queue) {
    return queue->size == 0;
}

void createStack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, int value) {
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->value = value;
    newElement->nextElement = stack->top;

    stack->top = newElement;
    stack->size++;
}

int pop(Stack *stack) {
    if (isEmptyStack(stack)) {
        return -1; // Indicador de pila vacía
    }

    Node *poppedElement = stack->top;
    stack->top = poppedElement->nextElement;
    stack->size--;

    int value = poppedElement->value;
    free(poppedElement);
    return value;
}

int isEmptyStack(Stack *stack) {
    return stack->size == 0;
}

void reverseQueue(Queue *queue) {
    Stack stack;
    createStack(&stack);

    while (!isEmptyQueue(queue)) {
        Node *element = deQueue(queue);
        push(&stack, element->value);
        free(element);
    }

    while (!isEmptyStack(&stack)) {
        int value = pop(&stack);
        enQueue(queue, value);
    }
}
