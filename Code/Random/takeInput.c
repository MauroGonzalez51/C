#include <stdio.h>
#include <stdlib.h>

char* takeInput(const char message[]) {
    char buffer[256];
    printf("%s", message);
    scanf("%s", buffer);
    while ((getchar()) != '\n');
    return copyString(buffer);
}

int main() { return EXIT_SUCCESS; }