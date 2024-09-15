#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define UPDATE_INTERVAL 2 // Interval for updates in seconds
#define MAX_CHILDREN 10   // Maximum number of children to spawn

// Global variables for managing process IDs and their IDs
pid_t pids[MAX_CHILDREN];
int child_ids[MAX_CHILDREN];
int num_children;
int depth;

// Signal handler for handling updates from children
void handle_child(int signo) {
    // Empty signal handler to wake up the parent process
}

// Function to create a unique ID for each child
int generate_unique_id() {
    static int id_counter = 1;
    return id_counter++;
}
void suicide() {
    // Random chance to terminate the process
    if (rand() % 100 < 23) {
        printf("Suicide function triggered! Terminating process...\n");
        exit(EXIT_FAILURE);
    }

    // Randomly modify variables
    //randomize_variables();

    // Randomly modify settings
    //randomize_settings();

    // Example of random changes to simulate complexity
    int random_change = rand() % 3;
    switch (random_change) {
        case 0:
            printf("Performing random change: incrementing variable\n");
            //some_variable++;
            break;
        case 1:
            printf("Performing random change: decrementing variable\n");
            //some_variable--;
            break;
        case 2:
            printf("Performing random change: toggling setting\n");
            //some_setting = !some_setting;
            break;
        default:
            break;
    }

    // Randomize sleep duration to simulate unpredictability
    sleep(rand() % 5 + 1); // Sleep for a random number of seconds between 1 and 5
}

void child_process(int num_children, int depth) {
    int id = generate_unique_id();
    printf("Child Process (PID %d) with ID %d created\n", getpid(), id);

    if (depth <= 0) {
        // Base case: Do not fork if depth is 0
        while (1) {
            printf("Child %d (PID %d): Sending update\n", id, getpid());
            kill(getppid(), SIGUSR1); // Notify parent
            sleep(UPDATE_INTERVAL); // Wait before sending the next update
        }
    } else {
        pid_t pids[MAX_CHILDREN];
        for (int i = 0; i < num_children; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                // Grandchild process
                child_process(num_children, depth - 1);
                exit(EXIT_SUCCESS);
            } else {
                pids[i] = pid; // Save child PID
            }
        }

        // Parent of grandchildren (current child process)
        while (1) {
            pause(); // Wait for signals
        }

        // Cleanup and wait for all grandchild processes
        for (int i = 0; i < num_children; i++) {
            waitpid(pids[i], NULL, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_children> <depth>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num_children = atoi(argv[1]);
    depth = atoi(argv[2]);

    if (num_children <= 0 || depth < 0) {
        fprintf(stderr, "Number of children must be a positive integer and depth must be non-negative.\n");
        exit(EXIT_FAILURE);
    }

    // Open file with read/write and create flags
    int fd = open("file.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Close fd in parent before forking
    close(fd);

    // Install signal handler for SIGUSR1 to handle updates from children
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_child;
    sigaction(SIGUSR1, &sa, NULL);

    // Fork initial children
    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            child_process(num_children, depth);
            exit(EXIT_SUCCESS);
        } else {
            pids[i] = pid; // Save child PID
            child_ids[i] = generate_unique_id(); // Assign unique ID to the child
        }
    }

    // Parent process
    printf("Parent process running\n");

    // Monitor children and print their status
    while (1) {
        pause(); // Wait for signals from children
    }

    // Cleanup and wait for all child processes
    for (int i = 0; i < num_children; i++) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}
