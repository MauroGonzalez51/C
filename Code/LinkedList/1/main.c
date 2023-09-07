#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "static_linked_list.h"
#include "functions.h"

void mainMenu() {
    int newCourse = 0;

    do {
        StaticLinkedList *list = createStaticLinkedList(30);
        printf("\n");

        list -> courseName = takeInput("Ingrese el nombre del curso: ");
        list -> ID = takeInput("Ingrese el [ ID / CODIGO ] del curso: ");

        int newStudent = 0, studentCounter = 0;

        do {
            StaticNode student;
            studentCounter++;

            printf("\nEstudiante [%d]\n", studentCounter);

            student.studentName = takeInput("Nombre del estudiante: ");
            student.ID = takeInput("Ingrese el codigo del estudiante: ");
            student.noIdentification = takeInput("Ingrese el numero de identificacion del estudiante: ");
            student.email = takeInput("Ingrese el correo electronico del estudiante: ");

            (insertAtEnd(list, student)) ? 
                log("Estudiante agregado correctamente") :
                log("Error al momento de guardar los datos");

            printf("\nDesea ingresar otro estudiante? (1/0): ");
            scanf("%d", &newStudent);
        } while (newStudent);

        printf("\nDesea ingresar otro curso? (1/0): ");
        scanf("%d", &newCourse);
    } while (newCourse);
}


int main(void) {
    mainMenu();
    return EXIT_SUCCESS;
}

