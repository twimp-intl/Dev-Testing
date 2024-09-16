#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>

int main() {
    pid_t target_pid = 1; // PID of the target process (e.g., init or systemd)
    struct user_regs_struct regs;
    long data;
    
    // Attach to the target process
    if (ptrace(PTRACE_ATTACH, target_pid, NULL, NULL) == -1) {
        perror("ptrace attach");
        return 1;
    }

    // Wait for the process to stop
    if (waitpid(target_pid, NULL, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    // Get the registers of the target process
    if (ptrace(PTRACE_GETREGS, target_pid, NULL, &regs) == -1) {
        perror("ptrace getregs");
        return 1;
    }

    // Print the instruction pointer (eip on x86, rip on x86_64)
    printf("Instruction pointer: %llx\n", (unsigned long long)regs.rip);

    // Read data from the target process (e.g., memory address)
    data = ptrace(PTRACE_PEEKDATA, target_pid, regs.rip, NULL);
    if (data == -1 && errno != 0) {
        perror("ptrace peekdata");
        return 1;
    }

    printf("Data at instruction pointer: %lx\n", data);

    // Detach from the target process
    if (ptrace(PTRACE_DETACH, target_pid, NULL, NULL) == -1) {
        perror("ptrace detach");
        return 1;
    }

    return 0;
}
