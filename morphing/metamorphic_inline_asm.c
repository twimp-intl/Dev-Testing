#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform simple addition with different assembly variants
void metamorphic_addition() {
    int a = 5, b = 3, result = 0;
    int choice = rand() % 2;

    switch (choice) {
        case 0:
            __asm__ (
                "movl %1, %%eax;\n"
                "addl %2, %%eax;\n"
                "movl %%eax, %0;\n"
                : "=r" (result)
                : "r" (a), "r" (b)
                : "%eax"
            );
            printf("Variant 1 (ADD instruction): %d + %d = %d\n", a, b, result);
            break;
        case 1:
            __asm__ (
                "movl %1, %%eax;\n"
                "subl %2, %%eax;\n"
                "negl %%eax;\n"
                "movl %%eax, %0;\n"
                : "=r" (result)
                : "r" (a), "r" (b)
                : "%eax"
            );
            printf("Variant 2 (SUB+NEG instruction): %d - (-%d) = %d\n", a, b, result);
            break;
    }
}

int main() {
    srand(time(NULL));  // Seed random number generator

    for (int i = 0; i < 5; i++) {
        metamorphic_addition();
    }

    return 0;
}
