#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_architecture_from_cpuinfo() {
    FILE *file = fopen("/proc/cpuinfo", "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "model name")) {
            printf("CPU Info: %s", line);
        }
    }

    fclose(file);
}

int main() {
    get_architecture_from_cpuinfo();
    return 0;
}
