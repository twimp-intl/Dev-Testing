#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define DISK_DEVICE "/dev/sda" // Replace with your disk device
#define BLOCK_SIZE 4096 // Adjust according to the disk's sector/block size
#define DATA "Hello, World!"

// Function to write data to a block
int write_block(int fd, off_t offset, const char *data, size_t size) {
    if (lseek(fd, offset, SEEK_SET) < 0) {
        perror("lseek");
        return -1;
    }
    if (write(fd, data, size) < 0) {
        perror("write");
        return -1;
    }
    return 0;
}

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

// Function to check if a block is free (by reading and checking content)
int is_block_free(int fd, off_t offset, size_t size) {
    char buffer[size];
    memset(buffer, 0, size);

    if (read_block(fd, offset, buffer, size) < 0) {
        return -1;
    }
    
    for (size_t i = 0; i < size; i++) {
        if (buffer[i] != 0) {
            return 0; // Block is not free
        }
    }
    return 1; // Block is free
}

int main() {
    int fd = open(DISK_DEVICE, O_RDWR); // Open the disk device file
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

    // Start from the end and search for a free block
    off_t current_offset;
    int block_found = 0;
    for (current_offset = disk_size - BLOCK_SIZE; current_offset >= 0; current_offset -= BLOCK_SIZE) {
        if (is_block_free(fd, current_offset, BLOCK_SIZE) == 1) {
            block_found = 1;
            break;
        }
    }

    if (!block_found) {
        fprintf(stderr, "No free block found\n");
        close(fd);
        return 1;
    }

    printf("Free block found at offset %lld\n", (long long)current_offset);

    // Write data to the found block
    if (write_block(fd, current_offset, DATA, sizeof(DATA)) < 0) {
        close(fd);
        return 1;
    }

    // Marking the block as bad is not directly possible through raw I/O alone.
    // This typically requires filesystem-level or disk utility commands.
    printf("Data written to the block\n");

    close(fd);
    return 0;
}
