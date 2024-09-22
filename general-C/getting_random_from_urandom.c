#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    unsigned int rand_num;

    // Open /dev/urandom
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Read a random number
    if (read(fd, &rand_num, sizeof(rand_num)) != sizeof(rand_num)) {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);

    // Use the random number
    printf("Random number from /dev/urandom: %u\n", rand_num);
    return 0;
}
