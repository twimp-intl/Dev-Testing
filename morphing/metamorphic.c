#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to generate a variant of the same computation using different operations
void generate_variant() {
    int choice = rand() % 3; // Choose a variant randomly
    int a = 5, b = 3, result;

    switch (choice) {
        case 0:
            // First variant using addition
            result = a + b;
            printf("Variant 1: %d + %d = %d\n", a, b, result);
            break;
        case 1:
            // Second variant using increment loop
            result = a;
            for (int i = 0; i < b; i++) {
                result++;
            }
            printf("Variant 2: Increment loop result = %d\n", result);
            break;
        case 2:
            // Third variant using subtraction and absolute value
            result = abs(a - (-b));
            printf("Variant 3: %d - (-%d) = %d\n", a, b, result);
            break;
    }
}

int main() {
    srand(time(NULL));  // Seed random number generator

    for (int i = 0; i < 5; i++) {
        printf("Execution %d:\n", i + 1);
        generate_variant();
        printf("---------------------------\n");
        sleep(1);  // Simulate time between executions
    }

    return 0;
}
