#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char *data = (char *)malloc(100);
    
    // Use data
    // ...

    free(data);  // First free
    free(data);  // Double free vulnerability
}

int main() {
    vulnerable_function();
    return 0;
}
