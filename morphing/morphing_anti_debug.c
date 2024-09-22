#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <time.h>
#include <signal.h>

// Anti-debugging: Detects if a debugger is attached using ptrace
int detect_debugger() {
    if (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1) {
        printf("Debugger detected! Exiting...\n");
        exit(1);
    }
    return 0;
}

// Anti-debugging: Timing check to detect delays caused by debugging
void timing_check() {
    clock_t start_time = clock();
    sleep(1);  // Sleep for 1 second
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (elapsed_time > 1.5) {  // If elapsed time is greater than expected
        printf("Timing discrepancy detected! Exiting...\n");
        exit(1);
    }
}

// Anti-debugging: Detect software breakpoints by modifying memory
void detect_breakpoint() {
    volatile int a = 5;
    volatile int b = 3;

    __asm__ volatile (
        "movl %1, %%eax;\n"
        "movl %%eax, %0;\n"
        : "=r" (a)
        : "r" (b)
        : "%eax"
    );

    if (a != b) {
        printf("Breakpoint detected! Exiting...\n");
        exit(1);
    }
}

// Anti-debugging: Detect single-stepping with signal handling
void signal_handler(int sig) {
    printf("Signal caught: %d\n", sig);
    exit(1);
}

void single_step_detection() {
    signal(SIGTRAP, signal_handler);  // Set trap signal handler

    __asm__ volatile (
        "int3;"  // Trigger a breakpoint interrupt to see if a debugger catches it
    );

    printf("No debugger detected (single-stepping test).\n");
}

// Self-modifying code: Modify the running code to evade breakpoints
void self_modifying_code() {
    unsigned char *code = (unsigned char *) &self_modifying_code;

    for (int i = 0; i < 10; i++) {
        code[i] ^= 0xFF;  // Flip bits in the code to make it harder to follow
    }

    printf("Self-modifying code executed.\n");
}

int main() {
    printf("Starting anti-debugging techniques...\n");

    detect_debugger();
    timing_check();
    detect_breakpoint();
    single_step_detection();
    self_modifying_code();

    printf("Program finished successfully.\n");
    return 0;
}
