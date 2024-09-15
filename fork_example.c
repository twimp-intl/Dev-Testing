#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#define MIN_CHILDREN 3
#define MAX_CHILDREN 7
#define DELAY 1 // Delay in seconds

volatile sig_atomic_t quit_flag = 0; // Signal flag

// Signal handler for Ctrl-C (SIGINT)
void handle_sigint(int sig) {
    printf("\nReceived SIGINT (Ctrl-C). Quitting gracefully...\n");
    quit_flag = 1; // Set the quit flag to break out of the loop
}

void fork_children(int depth, int max_depth, int pipe_fd[2]) {
    if (depth > max_depth) return;

    int num_children = MIN_CHILDREN + rand() % (MAX_CHILDREN - MIN_CHILDREN + 1);
    for (int i = 0; i < num_children; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            // Child process
            sleep(DELAY); // Simulate some work
            if (depth < max_depth) {
                // Create a pipe for inter-process communication
                int child_pipe[2];
                if (pipe(child_pipe) == -1) {
                    perror("pipe failed");
                    exit(EXIT_FAILURE);
                }
                fork_children(depth + 1, max_depth, child_pipe);
                
                // Close unused pipe ends
                close(child_pipe[1]);
                
                // Read data from the pipe
                char buffer[256];
                ssize_t bytes_read = read(child_pipe[0], buffer, sizeof(buffer));
                if (bytes_read > 0) {
                    write(pipe_fd[1], buffer, bytes_read); // Send data to parent
                }
                close(child_pipe[0]);
            }
            printf("Child PID: %d, Number of children: %d\n", getpid(), num_children);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            continue;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Set up signal handler for Ctrl-C
    signal(SIGINT, handle_sigint);

    // Create a pipe for inter-process communication
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork the initial set of children
    fork_children(1, 3, pipe_fd);

    // Close the write end of the pipe in the parent process
    close(pipe_fd[1]);

    // Main loop to keep the program running until Ctrl-C is pressed
    while (!quit_flag) {
        // Read and print the data received from child processes
        char buffer[256];
        ssize_t bytes_read = read(pipe_fd[0], buffer, sizeof(buffer));
        if (bytes_read > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }
        usleep(100000); // Add a small sleep to avoid busy-waiting
    }

    // Close the pipe and wait for all children to terminate
    close(pipe_fd[0]);
    while (wait(NULL) > 0); // Wait for all child processes to finish

    printf("Program terminated.\n");
    return 0;
}
