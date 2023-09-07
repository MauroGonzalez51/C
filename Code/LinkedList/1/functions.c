#include "functions.h"

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

void log(const char message[]) {
    printf("\n[ INFO ] %s\n", message);
}