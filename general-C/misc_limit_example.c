#include <sys/resource.h>
#include <stdio.h>

int main() {
    struct rlimit rl;
    if (getrlimit(RLIMIT_NOFILE, &rl) == 0) {
        printf("Soft limit: %ld\n", rl.rlim_cur);
        printf("Hard limit: %ld\n", rl.rlim_max);
    } else {
        perror("getrlimit");
    }
    return 0;
}
