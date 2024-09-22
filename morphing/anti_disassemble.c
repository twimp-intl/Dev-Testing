#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>

// Function to make it difficult to analyze by using self-modifying code
void obfuscate_code(void *func_ptr, size_t size) {
    unsigned char *code = (unsigned char *)func_ptr;
    for (size_t i = 0; i < size; i++) {
        // XOR each byte of the function with a random key to make it difficult to analyze
        code[i] ^= rand() % 256;
    }
}

void deobfuscate_code(void *func_ptr, size_t size) {
    unsigned char *code = (unsigned char *)func_ptr;
    for (size_t i = 0; i < size; i++) {
        // Reverse the XOR operation to restore the original code
        code[i] ^= rand() % 256;
    }
}

// The target function that will be obfuscated
void secret_function() {
    printf("Executing secret function!\n");
}

int main() {
    srand(time(NULL));

    // Set the memory protection to allow writing to the code segment (self-modifying code)
    size_t page_size = sysconf(_SC_PAGESIZE);
    void *secret_func_addr = (void *)((size_t)secret_function & ~(page_size - 1));
    if (mprotect(secret_func_addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        perror("mprotect");
        return 1;
    }

    // Obfuscate the secret function
    printf("Obfuscating the secret function...\n");
    obfuscate_code((void *)secret_function, 64);  // Obfuscate the first 64 bytes of the function

    // Optionally deobfuscate and execute the function at runtime
    printf("Deobfuscating and executing the secret function...\n");
    deobfuscate_code((void *)secret_function, 64);  // Deobfuscate the function
    secret_function();

    // Re-obfuscate to prevent further analysis
    printf("Re-obfuscating the secret function...\n");
    obfuscate_code((void *)secret_function, 64);

    return 0;
}
