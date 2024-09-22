#include <stdio.h>
#include <stdlib.h>

void vulnerable_function(unsigned int size) {
    char *buffer;
    
    // Dangerous allocation if size is very large
    buffer = (char *)malloc(size);
    
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return;
    }
    
    // Do something with the buffer
    // ...

    free(buffer);
}

int main() {
    unsigned int large_value = 0xFFFFFFFF; // Large value causing overflow
    vulnerable_function(large_value + 1); // Integer overflow during allocation
    return 0;
}
