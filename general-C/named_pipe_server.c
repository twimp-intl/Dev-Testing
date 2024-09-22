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
    const char *response = "hi";

    // Create named pipes (FIFOs) if they do not exist
    if (mkfifo(REQUEST_PIPE, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo request");
        exit(EXIT_FAILURE);
    }

    if (mkfifo(REPLY_PIPE, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo reply");
        exit(EXIT_FAILURE);
    }

    // Open the request pipe for reading
    request_fd = open(REQUEST_PIPE, O_RDONLY);
    if (request_fd == -1) {
        perror("open request");
        exit(EXIT_FAILURE);
    }

    // Open the reply pipe for writing
    reply_fd = open(REPLY_PIPE, O_WRONLY);
    if (reply_fd == -1) {
        perror("open reply");
        close(request_fd);
        exit(EXIT_FAILURE);
    }

    // Read message from the request pipe
    ssize_t num_bytes = read(request_fd, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read request");
        close(request_fd);
        close(reply_fd);
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';  // Null-terminate the received data
    printf("Received from client: %s\n", buffer);

    // Send a response to the reply pipe
    if (write(reply_fd, response, strlen(response)) == -1) {
        perror("write reply");
        close(request_fd);
        close(reply_fd);
        exit(EXIT_FAILURE);
    }

    // Close pipes
    close(request_fd);
    close(reply_fd);

    return 0;
}
