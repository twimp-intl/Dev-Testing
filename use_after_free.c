#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char *data = (char *)malloc(100);
    strcpy(data, "Sensitive Data");

    free(data); // Memory is freed

    // Accessing data after free
    printf("Data: %s\n", data); // Use-after-free vulnerability
}

int main() {
    vulnerable_function();
    return 0;
}
