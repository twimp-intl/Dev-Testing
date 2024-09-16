#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// Function that mimics the open() syscall using inline assembly
int my_open(const char *pathname, int flags, mode_t mode) {
    int fd;

    // Inline assembly for the open() system call on x86-64
    asm volatile (
        "mov $2, %%rax;"        // Syscall number for open() (2)
        "mov %1, %%rdi;"        // First argument: pathname
        "mov %2, %%rsi;"        // Second argument: flags
        "mov %3, %%rdx;"        // Third argument: mode
        "syscall;"              // Perform the system call
        "mov %%rax, %0;"        // Store return value in fd
        : "=r" (fd)             // Output (fd)
        : "r" (pathname), "r" (flags), "r" (mode) // Inputs
        : "%rax", "%rdi", "%rsi", "%rdx"  // Clobbered registers
    );

    if (fd < 0) {
        // Handle the error (fd will contain the negative error code)
        errno = -fd;
        return -1;
    }

    return fd;
}

int main() {
    // Use the my_open function to open a file
    int fd = my_open("testfile.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("my_open");
        return 1;
    }

    // Write to the file (if opened successfully)
    const char *message = "Hello, World!\n";
    write(fd, message, 14);

    // Close the file
    close(fd);

    return 0;
}
