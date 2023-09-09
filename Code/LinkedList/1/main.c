#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

#include "dynamic_linked_list.h"
#include "static_linked_list.h"
#include "functions.h"
#include "dashboard.h"
#include "selected_course.h"

#define MAX_STUDENTS_PER_COURSE 30

DynamicNode *SELECTED_COURSE = NULL;

void handleCase(DynamicLinkedList *list, int input) {
    switch (input) {
        case 1: {
            // * SHOW ALL THE COURSES STORED
            showAllCourses(list);
            break;
        }

        case 2: {
            // * SELECT A COURSE
            selectCourse(list);
            break;
        }

        case 3: {
            // * MODIFY A COURSE
            modifyCourse();
            break;
        }

        case 4: {
            // * DELETE A COURSE
            deleteCourse(list);
            break;
        }

        case 5: {
            showAllStudentsInSelectedCourse();
            break;
        }

        case 6: {
            insertStudent(SELECTED_COURSE -> list);
            break;
        }

        case 7: {
            deleteStudent();
            break;
        }

        case 8: {
            modifyStudent();
            break;
        }

        case 9: {
            averagePerCourse(list);
            break;
        }
        
        case 10: {
            averageInSelectedCourse();
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

        // * --------------------------------------------|>

        // + Course Related

        printf("1. Mostrar clases\n");
        printf("2. Seleccionar una clase\n");
        printf("3. Modificar una clase\n");
        printf("4. Eliminar una clase\n");

        // * --------------------------------------------|>

        // + Student Related

        printf("5. Ver todos los estudiantes en la clase\n");
        printf("6. Agregar un estudiante\n");
        printf("7. Eliminar un estudiante\n");
        printf("8. Modificar un estudiante\n");

        // * --------------------------------------------|>
        
        // + All courses

        printf("9. Promedio por clase\n");
        printf("10. Promedio en la clase seleccionada\n");

        printf("\nSeleccione un valor: ");
        scanf("%d", &input);

        handleCase(dynamicList, input);

        printf("\nTerminar ejecucion? (1/0): ");
        scanf("%d", &exit);
    } while (exit != 1); 
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
    srand(time(NULL));

    DynamicLinkedList *dynamicList = createDynamicLinkedList();

    mainMenu(dynamicList);

    dashboard(dynamicList);

    return EXIT_SUCCESS;
}

