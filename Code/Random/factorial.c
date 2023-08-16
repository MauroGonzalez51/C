#include <stdio.h>

#define EXIT_SUCCESS 0

int counter = 0;

int factorial(int n) {
    counter++;

    printf("\n");

    printf("Step %d\n", counter);
    
    printf("Currently multiplying: %d\n", n);

    printf("\n");

    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main(void) {
    int number;

    printf("Digit a number: ");
    scanf("%d", &number);

    printf("\nResult: %d\n", factorial(number));
    return EXIT_SUCCESS;
}