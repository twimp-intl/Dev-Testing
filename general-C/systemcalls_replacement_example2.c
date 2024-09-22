#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>

// Function to show syscall details
void show_syscall(int syscall_number, const char *description) {
    printf("Syscall number: %d for %s\n", syscall_number, description);
}

int main() {
    printf("Demonstration of simple Linux functions with assembly code:\n");

    // 1. `unlink()`
    show_syscall(87, "sys_unlink");
    __asm__ (
        "mov rax, 87      \n"  // syscall number for sys_unlink
        "mov rdi, rbx     \n"  // pathname pointer
        "syscall"
    );

    // 2. `mkdir()`
    show_syscall(83, "sys_mkdir");
    __asm__ (
        "mov rax, 83      \n"  // syscall number for sys_mkdir
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 3. `rmdir()`
    show_syscall(84, "sys_rmdir");
    __asm__ (
        "mov rax, 84      \n"  // syscall number for sys_rmdir
        "mov rdi, rbx     \n"  // pathname pointer
        "syscall"
    );

    // 4. `chmod()`
    show_syscall(90, "sys_chmod");
    __asm__ (
        "mov rax, 90      \n"  // syscall number for sys_chmod
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 5. `chown()`
    show_syscall(92, "sys_chown");
    __asm__ (
        "mov rax, 92      \n"  // syscall number for sys_chown
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // owner
        "mov rdx, r8      \n"  // group
        "syscall"
    );

    // 6. `pipe()`
    show_syscall(22, "sys_pipe");
    __asm__ (
        "mov rax, 22      \n"  // syscall number for sys_pipe
        "mov rdi, rbx     \n"  // pointer to file descriptors array
        "syscall"
    );

    // 7. `fork()`
    show_syscall(57, "sys_fork");
    __asm__ (
        "mov rax, 57      \n"  // syscall number for sys_fork
        "syscall"
    );

    // 8. `execve()`
    show_syscall(59, "sys_execve");
    __asm__ (
        "mov rax, 59      \n"  // syscall number for sys_execve
        "mov rdi, rbx     \n"  // filename pointer
        "mov rsi, rcx     \n"  // argv pointer
        "mov rdx, r8      \n"  // envp pointer
        "syscall"
    );

    // 9. `getuid()`
    show_syscall(102, "sys_getuid");
    __asm__ (
        "mov rax, 102     \n"  // syscall number for sys_getuid
        "syscall"
    );

    // 10. `getgid()`
    show_syscall(104, "sys_getgid");
    __asm__ (
        "mov rax, 104     \n"  // syscall number for sys_getgid
        "syscall"
    );

    // 11. `brk()`
    show_syscall(12, "sys_brk");
    __asm__ (
        "mov rax, 12      \n"  // syscall number for sys_brk
        "mov rdi, rbx     \n"  // end of data segment
        "syscall"
    );

    // 12. `mprotect()`
    show_syscall(10, "sys_mprotect");
    __asm__ (
        "mov rax, 10      \n"  // syscall number for sys_mprotect
        "mov rdi, rbx     \n"  // address
        "mov rsi, rcx     \n"  // length
        "mov rdx, r8      \n"  // protection
        "syscall"
    );

    // 13. `kill()`
    show_syscall(62, "sys_kill");
    __asm__ (
        "mov rax, 62      \n"  // syscall number for sys_kill
        "mov rdi, rbx     \n"  // process ID
        "mov rsi, rcx     \n"  // signal number
        "syscall"
    );

    // 14. `close()`
    show_syscall(3, "sys_close");
    __asm__ (
        "mov rax, 3       \n"  // syscall number for sys_close
        "mov rdi, rbx     \n"  // file descriptor
        "syscall"
    );

    // 15. `open()`
    show_syscall(2, "sys_open");
    __asm__ (
        "mov rax, 2       \n"  // syscall number for sys_open
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // flags
        "mov rdx, r8      \n"  // mode
        "syscall"
    );

    // 16. `read()`
    show_syscall(0, "sys_read");
    __asm__ (
        "mov rax, 0       \n"  // syscall number for sys_read
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // buffer
        "mov rdx, r8      \n"  // count
        "syscall"
    );

    // 17. `write()`
    show_syscall(1, "sys_write");
    __asm__ (
        "mov rax, 1       \n"  // syscall number for sys_write
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // buffer
        "mov rdx, r8      \n"  // count
        "syscall"
    );

    // 18. `dup()`
    show_syscall(32, "sys_dup");
    __asm__ (
        "mov rax, 32      \n"  // syscall number for sys_dup
        "mov rdi, rbx     \n"  // file descriptor
        "syscall"
    );

    // 19. `dup2()`
    show_syscall(33, "sys_dup2");
    __asm__ (
        "mov rax, 33      \n"  // syscall number for sys_dup2
        "mov rdi, rbx     \n"  // old file descriptor
        "mov rsi, rcx     \n"  // new file descriptor
        "syscall"
    );

    // 20. `fstat()`
    show_syscall(5, "sys_fstat");
    __asm__ (
        "mov rax, 5       \n"  // syscall number for sys_fstat
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // buffer
        "syscall"
    );

    // 21. `lseek()`
    show_syscall(8, "sys_lseek");
    __asm__ (
        "mov rax, 8       \n"  // syscall number for sys_lseek
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // offset
        "mov rdx, r8      \n"  // whence
        "syscall"
    );

    // 22. `stat()`
    show_syscall(4, "sys_stat");
    __asm__ (
        "mov rax, 4       \n"  // syscall number for sys_stat
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // buffer
        "syscall"
    );

    // 23. `lstat()`
    show_syscall(6, "sys_lstat");
    __asm__ (
        "mov rax, 6       \n"  // syscall number for sys_lstat
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // buffer
        "syscall"
    );

    // 24. `link()`
    show_syscall(9, "sys_link");
    __asm__ (
        "mov rax, 9       \n"  // syscall number for sys_link
        "mov rdi, rbx     \n"  // pathname pointer
        "mov rsi, rcx     \n"  // target pathname pointer
        "syscall"
    );

    // 25. `rename()`
    show_syscall(82, "sys_rename");
    __asm__ (
        "mov rax, 82      \n"  // syscall number for sys_rename
        "mov rdi, rbx     \n"  // old pathname pointer
        "mov rsi, rcx     \n"  // new pathname pointer
        "syscall"
    );

    return 0;
}
