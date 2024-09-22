#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    unsigned long entropy;
    if (ioctl(fd, RNDGETENTCNT, &entropy) == 0) {
        printf("Entropy: %lu\n", entropy);
    } else {
        perror("ioctl");
    }
    close(fd);
    return 0;
}
