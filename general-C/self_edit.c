#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

void modify_code() {
    // Example of machine code that increments a register (in x86-64)
    unsigned char code[] = { 0x48, 0xff, 0xc0, 0xc3 }; // "inc rax; ret"

    // Allocate executable memory
    void *mem = mmap(NULL, sizeof(code), PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        return;
    }

    // Copy the code into the executable memory
    memcpy(mem, code, sizeof(code));

    // Mark the memory as executable
    mprotect(mem, sizeof(code), PROT_EXEC);

    // Call the modified code
    int (*func)() = (int (*)())mem;
    printf("Result: %d\n", func()); // Output will be the modified result

    // Free the memory
    munmap(mem, sizeof(code));
}

int main() {
    modify_code();
    return 0;
}
