#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define NUM_CHILDREN 5
#define SHM_SIZE sizeof(int)

int *shared_mem;

// Signal handler for SIGINT
void handle_sigint(int sig) {
    // Unmap shared memory and exit
    munmap(shared_mem, SHM_SIZE);
    exit(EXIT_SUCCESS);
}

int main() {
    // Set up SIGINT signal handler
    signal(SIGINT, handle_sigint);

    // Create shared memory
    shared_mem = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize shared memory
    *shared_mem = 0;

    // Fork child processes
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            printf("Child %d (PID: %d) started.\n", i + 1, getpid());

            int old_value = *shared_mem;
            while (1) {
                // Poll for changes in shared memory
                if (*shared_mem != old_value) {
                    printf("Child %d (PID: %d) detected change in shared_mem. Exiting.\n", i + 1, getpid());
                    exit(EXIT_SUCCESS);
                }
                sleep(1);
            }
        }
    }

    // Parent process
    printf("Parent: All child processes have been spawned.\n");

    // Wait for a moment to let children start
    sleep(2);

    // Change the shared variable
    *shared_mem = 1;

    // Wait for all child processes to complete
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        wait(NULL);
    }

    // Clean up shared memory
    munmap(shared_mem, SHM_SIZE);

    // Keep the parent running until Ctrl-C is pressed
    printf("Parent: Press Ctrl-C to exit.\n");
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
