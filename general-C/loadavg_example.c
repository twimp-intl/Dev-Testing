#include <stdio.h>

int main() {
    FILE *file = fopen("/proc/loadavg", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    float load1, load5, load15;
    if (fscanf(file, "%f %f %f", &load1, &load5, &load15) == 3) {
        printf("Load average (1 min): %.2f\n", load1);
        printf("Load average (5 min): %.2f\n", load5);
        printf("Load average (15 min): %.2f\n", load15);
    } else {
        perror("fscanf");
    }

    fclose(file);
    return 0;
}
