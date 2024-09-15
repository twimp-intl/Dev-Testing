#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char path[1035];

    fp = popen("getconf LONG_BIT", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("Architecture: %s-bit\n", path);
    }

    pclose(fp);
    return 0;
}
