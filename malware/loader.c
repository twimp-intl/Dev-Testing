#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    // Open the binary file containing the machine code
    FILE *file = fopen("code.bin", "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to hold the machine code
    void *mem = mmap(NULL, file_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        fclose(file);
        return 1;
    }

    // Read the machine code into memory
    fread(mem, 1, file_size, file);
    fclose(file);

    // Cast the memory to a function pointer and execute it
    void (*func)() = (void (*)())mem;
    func(); // Call the function to execute the machine code

    // Clean up
    munmap(mem, file_size);

    return 0;
}
