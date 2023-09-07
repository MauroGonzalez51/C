#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_linked_list.h"
#include "static_linked_list.h"
#include "functions.h"

#define MAX_STUDENTS_PER_COURSE 30

// * ---------------------------------------------------------------------------------------------------------|>

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

// * ---------------------------------------------------------------------------------------------------------|>

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

// * ---------------------------------------------------------------------------------------------------------|>

void handleCase(DynamicLinkedList *list, int input) {
    switch (input) {
        case 1: {
            // * SHOW ALL THE CLASSES STORED
            showAllCourses(list);
            break;
        }

        case 2: {
            // * MODIFY THE COURSE [ CourseName, ID ]
            modifyCourse(list);
            break;
        }

        default:
            exit(EXIT_FAILURE);
    }
}

void dashboard(DynamicLinkedList *dynamicList) {
    int input, exit = 0; 

    do {
        printf("\n");
        printf("1. Mostrar clases\n");
        printf("2. Modificar clases\n");
        printf("3. Modificar alumnos en una clase\n");
        printf("4. Eliminar alumnos en una clase\n");

        printf("\nSeleccione un valor: ");
        scanf("%d", &input);

        handleCase(dynamicList, input);

        printf("\nTerminar ejecucion? (1/0): ");
        scanf("%d", &exit);
    } while (exit != 1); 
}

void insertStudent(StaticLinkedList *list) {
    StaticNode student;

    student.studentName = takeInput("Nombre del estudiante: ");
    student.ID = takeInput("Ingrese el codigo del estudiante: ");
    student.noIdentification = takeInput("Ingrese el numero de identificacion del estudiante: ");
    student.email = takeInput("Ingrese el correo electronico del estudiante: ");

    (insertAtEnd(list, student)) ? 
        log("Estudiante agregado correctamente") :
        log("Error al momento de guardar los datos");
}

void mainMenu(DynamicLinkedList *dynamicList) {
    int newCourse = 0;

    do {
        StaticLinkedList *list = createStaticLinkedList(MAX_STUDENTS_PER_COURSE);
        printf("\n");

        list -> courseName = takeInput("Ingrese el nombre del curso: ");
        list -> ID = takeInput("Ingrese el [ ID / CODIGO ] del curso: ");

        int newStudent = 0, studentCounter = 0;

        do {
            studentCounter++;

            printf("\nEstudiante [%d]\n", studentCounter);

            insertStudent(list);

            printf("\nDesea ingresar otro estudiante? (1/0): ");
            scanf("%d", &newStudent);
        } while (newStudent);

        (insertInList(dynamicList, list)) ?
            log("Clase agregada correctamente") :
            log("Error al momento de guardar la clase");

        printf("\nDesea ingresar otro curso? (1/0): ");
        scanf("%d", &newCourse);
    } while (newCourse);
}

int main(void) {
    DynamicLinkedList *dynamicList = createDynamicLinkedList();

    mainMenu(dynamicList);

    dashboard(dynamicList);

    return EXIT_SUCCESS;
}

