#include "dashboard.h"

int selectedCourseExists() {
    return SELECTED_COURSE ? 1 : 0;
}

int printSelectedCourse() {
    if (!selectedCourseExists()) { return 0; }

    printf("\nCurso seleccionado: [ Nombre del curso: %s | ID: %s ]\n", 
        SELECTED_COURSE -> list -> courseName, 
        SELECTED_COURSE -> list -> ID
    );

    return 1;
}

int confirmation(const char message[]) {
    int flag;
    printf("%s (1/0): ", message);
    scanf("%d", &flag);
    return flag;
}

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

void selectCourse(DynamicLinkedList *list) {
    int selectedIndex;

    showAllCourses(list);

    printf("\n\nInserte el [ INDEX ] de la clase a seleccionar: ");
    scanf("%d", &selectedIndex);

    selectedIndex--;

    SELECTED_COURSE = getElementByIndex(list, selectedIndex);

    if (!SELECTED_COURSE) {
        log("Error: El elemento no existe"); SELECTED_COURSE = NULL; return;
    } else log("Elemento seleccionado correctamente");
}

void modifyCourse() {
    if (!printSelectedCourse()) { log("Error: Seleccione un curso primero"); return; }

    SELECTED_COURSE -> list -> courseName = takeInput("Nuevo nombre del curso: ");
    SELECTED_COURSE -> list -> ID = takeInput("Nuevo [ ID / CODIGO ] del curso: ");
}

void deleteCourse(DynamicLinkedList *list) {
    if (!printSelectedCourse()) { log("Error: Seleccione un curso primero"); return; }

    if (!confirmation("Estas seguro que quieres eliminar el curso?")) { return; }

    if (list -> head == NULL) { return; }

    // * Checking if head is the element to delete

    if (
        (strcmp(list -> head -> list -> courseName, SELECTED_COURSE -> list -> courseName) == 0) &&
        (strcmp(list -> head -> list -> ID, SELECTED_COURSE -> list -> ID) == 0)
    ) {
        DynamicNode *temp = list -> head;
        list -> head = list -> head -> nextElement;
        free(temp);
        list -> size--;
        log("Curso eliminado correctamente");
        return;
    }

    // * Rest of the list

    DynamicNode *current = list -> head;
    while (
        (current -> nextElement != NULL) && 
        (strcmp(current -> nextElement -> list -> courseName, SELECTED_COURSE -> list -> courseName) != 0) &&
        (strcmp(current -> nextElement -> list -> ID, SELECTED_COURSE -> list -> ID) != 0)
    ) {
        current = current -> nextElement;
    }

    if (current -> nextElement == NULL) { return; }

    DynamicNode *temp = current -> nextElement;
    current -> nextElement = temp -> nextElement;
    free(temp);
    list -> size--;
    log("Curso eliminado correctamente");
}

void showAllStudents() {
    if (!printSelectedCourse()) { log("Error: Seleccione un curso primero"); return; }

    int studentCount = 0;
    StaticNode *current = SELECTED_COURSE -> list -> head;
    while (current != NULL) {
        studentCount++;
        println(30);

        printf("[%d]\n\n", studentCount);

        printf("Nombre del estudiante: %s\n", current -> studentName);
        printf("[ ID / CODIGO ]: %s\n", current -> ID);
        printf("Numero de identificacion: %s\n", current -> noIdentification);
        printf("Correo electronico: %s\n", current -> email);

        current = current -> nextElement;
    }
}