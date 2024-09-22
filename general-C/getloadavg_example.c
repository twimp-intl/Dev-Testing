#include <stdio.h>
#include <unistd.h>

int main() {
    double loadavg[3];

    if (getloadavg(loadavg, 3) == -1) {
        perror("getloadavg");
        return 1;
    }

    printf("Load average (1 min): %.2f\n", loadavg[0]);
    printf("Load average (5 min): %.2f\n", loadavg[1]);
    printf("Load average (15 min): %.2f\n", loadavg[2]);

    return 0;
}
