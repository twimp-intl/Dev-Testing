#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define REQUEST_PIPE "/tmp/pipe_request"
#define REPLY_PIPE "/tmp/pipe_reply"
#define BUFFER_SIZE 100

int main() {
    int request_fd, reply_fd;
    char buffer[BUFFER_SIZE];
    const char *message = "hello";

    // Open the request pipe for writing
    request_fd = open(REQUEST_PIPE, O_WRONLY);
    if (request_fd == -1) {
        perror("open request");
        exit(EXIT_FAILURE);
    }

    // Open the reply pipe for reading
    reply_fd = open(REPLY_PIPE, O_RDONLY);
    if (reply_fd == -1) {
        perror("open reply");
        close(request_fd);
        exit(EXIT_FAILURE);
    }

    // Send a message to the request pipe
    if (write(request_fd, message, strlen(message)) == -1) {
        perror("write request");
        close(request_fd);
        close(reply_fd);
        exit(EXIT_FAILURE);
    }

    // Read the response from the reply pipe
    ssize_t num_bytes = read(reply_fd, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read reply");
        close(request_fd);
        close(reply_fd);
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';  // Null-terminate the received data
    printf("Received from server: %s\n", buffer);

    // Close pipes
    close(request_fd);
    close(reply_fd);

    return 0;
}
