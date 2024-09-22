#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];  // Pipe file descriptors
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (client)
        // Close unused read end
        close(pipefd[0]);

        // Send a "hello" message to the pipe
        const char *message = "hello";
        if (write(pipefd[1], message, strlen(message)) == -1) {
            perror("write");
            close(pipefd[1]);
            exit(EXIT_FAILURE);
        }

        // Close pipe
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {  // Parent process (client)
        // Close unused write end
        close(pipefd[1]);

        // Wait for the child process to be ready
        sleep(1);

        // Read response from the pipe
        ssize_t num_bytes = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (num_bytes == -1) {
            perror("read");
            close(pipefd[0]);
            exit(EXIT_FAILURE);
        }

        buffer[num_bytes] = '\0';  // Null-terminate the received data
        printf("Received from server: %s\n", buffer);

        // Close pipe
        close(pipefd[0]);

        // Wait for child process to finish
        wait(NULL);
    }

    return 0;
}
