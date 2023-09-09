#include <stdio.h>
#include <stdlib.h>

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

int main() { return EXIT_SUCCESS; }