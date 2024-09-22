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
volatile sig_atomic_t running = 1; // Flag to indicate if the parent is running

// Signal handler for SIGINT
void handle_sigint(int sig) {
    running = 0;
    // Clean up shared memory
    munmap(shared_mem, SHM_SIZE);
    exit(EXIT_SUCCESS);
}

// Function to create child processes
void create_children(int num_children) {
    for (int i = 0; i < num_children; ++i) {
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

    // Create initial children
    create_children(NUM_CHILDREN);

    // Parent process
    printf("Parent: All child processes have been spawned.\n");

    while (running) {
        // Wait for all child processes to complete
        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG);

        // If no child is found, it means all children are dead
        if (pid == 0) {
            // Create new children if needed
            create_children(NUM_CHILDREN);
        } else if (pid > 0) {
            // Check if all child processes are dead
            int all_dead = 1;
            for (int i = 0; i < NUM_CHILDREN; ++i) {
                pid_t check_pid = waitpid(-1, &status, WNOHANG);
                if (check_pid == 0) {
                    all_dead = 0;
                    break;
                }
            }
            if (all_dead) {
                // All children are dead, create new children
                create_children(NUM_CHILDREN);
            }
        }

        // Change the shared variable after a moment
        sleep(10);
        *shared_mem = 1;

        // Wait a bit before checking for children status again
        sleep(1);
    }

    // Clean up shared memory before exiting
    munmap(shared_mem, SHM_SIZE);

    return 0;
}
