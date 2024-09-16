#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void print_cpu_info();
void print_memory_info();
void print_system_info();

int main() {
    printf("System Information:\n");
    print_cpu_info();
    print_memory_info();
    print_system_info();

    return 0;
}

void print_cpu_info() {
    FILE *file = fopen("/proc/cpuinfo", "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("\nCPU Information:\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "model name") || strstr(line, "cpu cores") || strstr(line, "cpu MHz")) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void print_memory_info() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("\nMemory Information:\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "MemTotal") || strstr(line, "MemFree") || strstr(line, "Buffers") || strstr(line, "Cached")) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void print_system_info() {
    FILE *file = fopen("/proc/sys/kernel/osrelease", "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("\nSystem Information:\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("Kernel Release: %s", line);
    }
    fclose(file);

    file = fopen("/proc/uptime", "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("System Uptime: %s", line);
    }
    fclose(file);
}
