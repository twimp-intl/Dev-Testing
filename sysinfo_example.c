#include <sys/sysinfo.h>
#include <stdio.h>

int main() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Uptime: %ld seconds\n", info.uptime);
        printf("Total RAM: %lu bytes\n", info.totalram);
        printf("Free RAM: %lu bytes\n", info.freeram);
        printf("Load average: %.2f %.2f %.2f\n",
               info.loads[0] / (float)1 << SI_LOAD_SHIFT,
               info.loads[1] / (float)1 << SI_LOAD_SHIFT,
               info.loads[2] / (float)1 << SI_LOAD_SHIFT);
    } else {
        perror("sysinfo");
    }
    return 0;
}
