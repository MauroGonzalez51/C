#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USERS 2

#include "queue.h"

void println(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Queue queue;
    createQueue(&queue);

    for (int i = 0; i < USERS; i++) {
        printf("\n");
        println(40);

        Node node;

        printf("Ingrese su nombre de usuario: ");
        char userName[50];
        scanf("%s", userName);

        node.userName = (char *)malloc(strlen(userName + 1) * sizeof(char));
        strcpy(node.userName, userName);

        printf("Ingrese la cantidad de paginas: ");
        scanf("%d", &node.pageSize);

        enQueue(&queue, node);
    }

    printf("\n\n\nProcesando solicitudes ...\n");
    printQueue(&queue);

    return EXIT_SUCCESS;
}
