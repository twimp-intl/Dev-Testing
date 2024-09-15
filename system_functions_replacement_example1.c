#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

// Function to show syscall details
void show_syscall(int syscall_number, const char *description) {
    printf("Syscall number: %d for %s\n", syscall_number, description);
}

int main() {
    printf("Demonstration of common syscalls and functions with assembly code:\n");

    // 1. `open()`
    show_syscall(2, "sys_open");
    __asm__ (
        "mov rax, 2       \n"  // syscall number for sys_open
        "mov rdi, rbx     \n"  // filename
        "mov rsi, rcx     \n"  // flags
        "mov rdx, r8      \n"  // mode
        "syscall"
    );

    // 2. `read()`
    show_syscall(0, "sys_read");
    __asm__ (
        "mov rax, 0       \n"  // syscall number for sys_read
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // buffer
        "mov rdx, r8      \n"  // count
        "syscall"
    );

    // 3. `write()`
    show_syscall(1, "sys_write");
    __asm__ (
        "mov rax, 1       \n"  // syscall number for sys_write
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // buffer
        "mov rdx, r8      \n"  // count
        "syscall"
    );

    // 4. `close()`
    show_syscall(3, "sys_close");
    __asm__ (
        "mov rax, 3       \n"  // syscall number for sys_close
        "mov rdi, rbx     \n"  // file descriptor
        "syscall"
    );

    // 5. `mmap()`
    show_syscall(9, "sys_mmap");
    __asm__ (
        "mov rax, 9       \n"  // syscall number for sys_mmap
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // length
        "mov rdx, r8      \n"  // prot
        "mov r10, r9      \n"  // flags
        "mov r11, r12     \n"  // fd
        "mov r12, r13     \n"  // offset
        "syscall"
    );

    // 6. `munmap()`
    show_syscall(11, "sys_munmap");
    __asm__ (
        "mov rax, 11      \n"  // syscall number for sys_munmap
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // length
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
        "mov rdi, rbx     \n"  // filename
        "mov rsi, rcx     \n"  // argv
        "mov rdx, r8      \n"  // envp
        "syscall"
    );

    // 9. `wait4()`
    show_syscall(61, "sys_wait4");
    __asm__ (
        "mov rax, 61      \n"  // syscall number for sys_wait4
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // status
        "mov rdx, r8      \n"  // options
        "mov r10, r9      \n"  // rusage
        "syscall"
    );

    // 10. `kill()`
    show_syscall(62, "sys_kill");
    __asm__ (
        "mov rax, 62      \n"  // syscall number for sys_kill
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // sig
        "syscall"
    );

    // 11. `pipe()`
    show_syscall(22, "sys_pipe");
    __asm__ (
        "mov rax, 22      \n"  // syscall number for sys_pipe
        "mov rdi, rbx     \n"  // pipefd pointer
        "syscall"
    );

    // 12. `dup()`
    show_syscall(32, "sys_dup");
    __asm__ (
        "mov rax, 32      \n"  // syscall number for sys_dup
        "mov rdi, rbx     \n"  // oldfd
        "syscall"
    );

    // 13. `dup2()`
    show_syscall(33, "sys_dup2");
    __asm__ (
        "mov rax, 33      \n"  // syscall number for sys_dup2
        "mov rdi, rbx     \n"  // oldfd
        "mov rsi, rcx     \n"  // newfd
        "syscall"
    );

    // 14. `fstat()`
    show_syscall(5, "sys_fstat");
    __asm__ (
        "mov rax, 5       \n"  // syscall number for sys_fstat
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 15. `stat()`
    show_syscall(4, "sys_stat");
    __asm__ (
        "mov rax, 4       \n"  // syscall number for sys_stat
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 16. `lstat()`
    show_syscall(6, "sys_lstat");
    __asm__ (
        "mov rax, 6       \n"  // syscall number for sys_lstat
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 17. `rename()`
    show_syscall(82, "sys_rename");
    __asm__ (
        "mov rax, 82      \n"  // syscall number for sys_rename
        "mov rdi, rbx     \n"  // oldpath
        "mov rsi, rcx     \n"  // newpath
        "syscall"
    );

    // 18. `unlink()`
    show_syscall(87, "sys_unlink");
    __asm__ (
        "mov rax, 87      \n"  // syscall number for sys_unlink
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 19. `mkdir()`
    show_syscall(83, "sys_mkdir");
    __asm__ (
        "mov rax, 83      \n"  // syscall number for sys_mkdir
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 20. `rmdir()`
    show_syscall(84, "sys_rmdir");
    __asm__ (
        "mov rax, 84      \n"  // syscall number for sys_rmdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 21. `chdir()`
    show_syscall(80, "sys_chdir");
    __asm__ (
        "mov rax, 80      \n"  // syscall number for sys_chdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 22. `fchdir()`
    show_syscall(81, "sys_fchdir");
    __asm__ (
        "mov rax, 81      \n"  // syscall number for sys_fchdir
        "mov rdi, rbx     \n"  // fd
        "syscall"
    );

    // 23. `access()`
    show_syscall(21, "sys_access");
    __asm__ (
        "mov rax, 21      \n"  // syscall number for sys_access
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 24. `chmod()`
    show_syscall(90, "sys_chmod");
    __asm__ (
        "mov rax, 90      \n"  // syscall number for sys_chmod
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 25. `chown()`
    show_syscall(92, "sys_chown");
    __asm__ (
        "mov rax, 92      \n"  // syscall number for sys_chown
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // owner
        "mov rdx, r8      \n"  // group
        "syscall"
    );

    // 26. `umask()`
    show_syscall(60, "sys_umask");
    __asm__ (
        "mov rax, 60      \n"  // syscall number for sys_umask
        "mov rdi, rbx     \n"  // mask
        "syscall"
    );

    // 27. `getpid()`
    show_syscall(39, "sys_getpid");
    __asm__ (
        "mov rax, 39      \n"  // syscall number for sys_getpid
        "syscall"
    );

    // 28. `getppid()`
    show_syscall(110, "sys_getppid");
    __asm__ (
        "mov rax, 110     \n"  // syscall number for sys_getppid
        "syscall"
    );

    // 29. `setsid()`
    show_syscall(66, "sys_setsid");
    __asm__ (
        "mov rax, 66      \n"  // syscall number for sys_setsid
        "syscall"
    );

    // 30. `getuid()`
    show_syscall(102, "sys_getuid");
    __asm__ (
        "mov rax, 102     \n"  // syscall number for sys_getuid
        "syscall"
    );

    return 0;
}
