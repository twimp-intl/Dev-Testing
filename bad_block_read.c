#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define DISK_DEVICE "/dev/sda" // Replace with your disk device
#define BLOCK_SIZE 4096 // Adjust according to the disk's sector/block size

// Function to read a block
int read_block(int fd, off_t offset, char *buffer, size_t size) {
    if (lseek(fd, offset, SEEK_SET) < 0) {
        perror("lseek");
        return -1;
    }
    if (read(fd, buffer, size) < 0) {
        perror("read");
        return -1;
    }
    return 0;
}

// Function to check if a block is bad (by reading and checking content)
int check_if_block_is_bad(int fd, off_t offset, size_t size) {
    char buffer[size];
    memset(buffer, 0, size);

    if (read_block(fd, offset, buffer, size) < 0) {
        return 1; // Error indicates a potentially bad block
    }

    // Check if the block contains readable data
    for (size_t i = 0; i < size; i++) {
        if (buffer[i] != 0) {
            return 0; // Block is not bad
        }
    }
    return 0; // Block appears to be bad
}

int main() {
    int fd = open(DISK_DEVICE, O_RDONLY); // Open the disk device file for reading
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t disk_size;
    if (lseek(fd, 0, SEEK_END) < 0) {
        perror("lseek end");
        close(fd);
        return 1;
    }
    disk_size = lseek(fd, 0, SEEK_CUR);

    // Start from the end and search for a bad block
    off_t current_offset;
    int block_found = 0;
    for (current_offset = disk_size - BLOCK_SIZE; current_offset >= 0; current_offset -= BLOCK_SIZE) {
        if (check_if_block_is_bad(fd, current_offset, BLOCK_SIZE) == 1) {
            block_found = 1;
            break;
        }
    }

    if (!block_found) {
        fprintf(stderr, "No bad block found\n");
        close(fd);
        return 1;
    }

    printf("Bad block found at offset %lld\n", (long long)current_offset);

    // Attempt to read from the bad block
    char buffer[BLOCK_SIZE];
    if (read_block(fd, current_offset, buffer, BLOCK_SIZE) < 0) {
        fprintf(stderr, "Failed to read from bad block at offset %lld\n", (long long)current_offset);
    } else {
        printf("Successfully read from bad block at offset %lld\n", (long long)current_offset);
    }

    close(fd);
    return 0;
}
