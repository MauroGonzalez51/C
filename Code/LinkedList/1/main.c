#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "static_linked_list.h"

char* copyString(const char input[]) {
    size_t length = strlen(input);
    char* target = (char *)malloc(length + 1);

    if (target != NULL) {
        strcpy(target, input);
        return target;
    } else {
        fprintf(stderr, "Error: No se pudo asignar memoria para la cadena.\n");
        exit(EXIT_FAILURE);
    }
}

char* takeInput(const char message[]) {
    char buffer[256];
    printf("%s", message);
    scanf("%s", buffer);
    while ((getchar()) != '\n');
    return copyString(buffer);
}

void mainMenu() {
    int newCourse = 0;

    do {
        int newStudent = 0, studentCounter = 0;

        StaticLinkedList *list = createStaticLinkedList(30);
        printf("\n\n");

        list -> courseName = takeInput("Ingrese el nombre del curso: ");
        list -> ID = takeInput("Ingrese el [ ID / CODIGO ] del curso: ");

        do {
            Node student;
            studentCounter++;

            printf("\nEstudiante [%d]\n", studentCounter);

            student.studentName = takeInput("Nombre del estudiante: ");
            student.ID = takeInput("Ingrese el codigo del estudiante: ");
            student.noIdentification = takeInput("Ingrese el numero de identificacion del estudiante: ");
            student.email = takeInput("Ingrese el correo electronico del estudiante: ");

            printf("%s | %s | %s | %s\n", student.studentName, student.ID, student.noIdentification, student.email);

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

