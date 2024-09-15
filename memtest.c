#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <string.h>

#define CHUNK_SIZE (1024 * 1024) // 1 MB

void print_memory_info() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("System memory info:\n");
        printf("  Total RAM: %lu MB\n", info.totalram / (1024 * 1024));
        printf("  Free RAM: %lu MB\n", info.freeram / (1024 * 1024));
    } else {
        perror("sysinfo");
    }

    struct rlimit rlim;
    if (getrlimit(RLIMIT_AS, &rlim) == 0) {
        printf("Memory limits:\n");
        printf("  Soft limit: %lu MB\n", rlim.rlim_cur / (1024 * 1024));
        printf("  Hard limit: %lu MB\n", rlim.rlim_max / (1024 * 1024));
    } else {
        perror("getrlimit");
    }
}

int main() {
    // Print initial memory info
    print_memory_info();

    // Allocate memory in chunks and report
    void *ptr = NULL;
    size_t allocated_size = 0;
    size_t total_allocated = 0;

    while (1) {
        ptr = malloc(CHUNK_SIZE);
        if (ptr == NULL) {
            printf("Failed to allocate %zu MB\n", total_allocated / (1024 * 1024));
            break;
        }
        memset(ptr, 0, CHUNK_SIZE); // Prevent potential optimizations

        total_allocated += CHUNK_SIZE;
        printf("Successfully allocated %zu MB\n", total_allocated / (1024 * 1024));
        // Free the memory to avoid memory leaks
        free(ptr);
    }

    printf("Maximum allocatable memory: %zu MB\n", total_allocated / (1024 * 1024));

    // Print final memory info
    print_memory_info();

    return 0;
}
