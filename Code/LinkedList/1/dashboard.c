#include "dashboard.h"

void showAllCourses(DynamicLinkedList *list) {
    DynamicNode *dynamicNode = list->head;

    int classCount = 0;

    while (dynamicNode != NULL) {
        classCount++;

        println(40);

        printf("[%d]\n\n", classCount);

        printf("Nombre del curso: %s\n", dynamicNode -> list -> courseName);
        printf("[ ID / Codigo ] del curso: %s\n", dynamicNode -> list -> ID);

        dynamicNode = dynamicNode->nextElement;
    }
}

void modifyCourse(DynamicLinkedList *list) {
    int indexToModify;

    showAllCourses(list);

    printf("\n\nInserte el [ INDEX ] de la clase a modificar: ");
    scanf("%d", &indexToModify);

    indexToModify--;

    DynamicNode *course = getElementByIndex(list, indexToModify);

    if (!course) {
        log("Error: El elemento no existe"); return;
    } else log("Elemento identificado correctamente");

    course -> list -> courseName = takeInput("Nuevo nombre del curso: ");
    course -> list -> ID = takeInput("Nuevo [ ID / CODIGO ] del curso: ");
}