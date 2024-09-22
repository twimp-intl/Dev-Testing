#include <stdio.h>

// Function to display the syscall number and corresponding assembly code
void show_syscall(int num, const char* name) {
    printf("System Call: %s\n", name);
    printf("Assembly Code:\n");
}

int main() {
    // 1. `sys_symlink()`
    show_syscall(257, "sys_symlink");
    __asm__ (
        "mov rax, 257     \n"  // syscall number for sys_symlink
        "mov rdi, rax     \n"  // old_path
        "mov rsi, rbx     \n"  // new_path
        "syscall"
    );

    // 2. `sys_readlink()`
    show_syscall(258, "sys_readlink");
    __asm__ (
        "mov rax, 258     \n"  // syscall number for sys_readlink
        "mov rdi, rax     \n"  // pathname
        "mov rsi, rbx     \n"  // buf
        "mov rdx, rcx     \n"  // bufsiz
        "syscall"
    );

    // 3. `sys_mkdir()`
    show_syscall(83, "sys_mkdir");
    __asm__ (
        "mov rax, 83      \n"  // syscall number for sys_mkdir
        "mov rdi, rax     \n"  // pathname
        "mov rsi, rbx     \n"  // mode
        "syscall"
    );

    // 4. `sys_rmdir()`
    show_syscall(84, "sys_rmdir");
    __asm__ (
        "mov rax, 84      \n"  // syscall number for sys_rmdir
        "mov rdi, rax     \n"  // pathname
        "syscall"
    );

    // 5. `sys_statfs()`
    show_syscall(99, "sys_statfs");
    __asm__ (
        "mov rax, 99      \n"  // syscall number for sys_statfs
        "mov rdi, rax     \n"  // path
        "mov rsi, rbx     \n"  // buf
        "syscall"
    );

    // 6. `sys_fstatfs()`
    show_syscall(100, "sys_fstatfs");
    __asm__ (
        "mov rax, 100     \n"  // syscall number for sys_fstatfs
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // buf
        "syscall"
    );

    // 7. `sys_getpid()`
    show_syscall(39, "sys_getpid");
    __asm__ (
        "mov rax, 39      \n"  // syscall number for sys_getpid
        "syscall"
    );

    // 8. `sys_setpgid()`
    show_syscall(109, "sys_setpgid");
    __asm__ (
        "mov rax, 109     \n"  // syscall number for sys_setpgid
        "mov rdi, rax     \n"  // pid
        "mov rsi, rbx     \n"  // pgid
        "syscall"
    );

    // 9. `sys_getpgrp()`
    show_syscall(109, "sys_getpgrp");
    __asm__ (
        "mov rax, 109     \n"  // syscall number for sys_getpgrp
        "syscall"
    );

    // 10. `sys_setsid()`
    show_syscall(66, "sys_setsid");
    __asm__ (
        "mov rax, 66      \n"  // syscall number for sys_setsid
        "syscall"
    );

    // 11. `sys_setreuid()`
    show_syscall(70, "sys_setreuid");
    __asm__ (
        "mov rax, 70      \n"  // syscall number for sys_setreuid
        "mov rdi, rax     \n"  // ruid
        "mov rsi, rbx     \n"  // euid
        "syscall"
    );

    // 12. `sys_setregid()`
    show_syscall(71, "sys_setregid");
    __asm__ (
        "mov rax, 71      \n"  // syscall number for sys_setregid
        "mov rdi, rax     \n"  // rgid
        "mov rsi, rbx     \n"  // egid
        "syscall"
    );

    // 13. `sys_getppid()`
    show_syscall(110, "sys_getppid");
    __asm__ (
        "mov rax, 110     \n"  // syscall number for sys_getppid
        "syscall"
    );

    // 14. `sys_wait4()`
    show_syscall(114, "sys_wait4");
    __asm__ (
        "mov rax, 114     \n"  // syscall number for sys_wait4
        "mov rdi, rax     \n"  // pid
        "mov rsi, rbx     \n"  // stat_loc
        "mov rdx, rcx     \n"  // options
        "mov r10, rdx     \n"  // rusage
        "syscall"
    );

    // 15. `sys_mprotect()`
    show_syscall(125, "sys_mprotect");
    __asm__ (
        "mov rax, 125     \n"  // syscall number for sys_mprotect
        "mov rdi, rax     \n"  // addr
        "mov rsi, rbx     \n"  // len
        "mov rdx, rcx     \n"  // prot
        "syscall"
    );

    // 16. `sys_msync()`
    show_syscall(144, "sys_msync");
    __asm__ (
        "mov rax, 144     \n"  // syscall number for sys_msync
        "mov rdi, rax     \n"  // addr
        "mov rsi, rbx     \n"  // len
        "mov rdx, rcx     \n"  // flags
        "syscall"
    );

    // 17. `sys_madvise()`
    show_syscall(205, "sys_madvise");
    __asm__ (
        "mov rax, 205     \n"  // syscall number for sys_madvise
        "mov rdi, rax     \n"  // addr
        "mov rsi, rbx     \n"  // len
        "mov rdx, rcx     \n"  // behavior
        "syscall"
    );

    // 18. `sys_mremap()`
    show_syscall(25, "sys_mremap");
    __asm__ (
        "mov rax, 25      \n"  // syscall number for sys_mremap
        "mov rdi, rax     \n"  // addr
        "mov rsi, rbx     \n"  // old_len
        "mov rdx, rcx     \n"  // new_len
        "mov r10, rbx     \n"  // flags
        "syscall"
    );

    // 19. `sys_msgget()`
    show_syscall(190, "sys_msgget");
    __asm__ (
        "mov rax, 190     \n"  // syscall number for sys_msgget
        "mov rdi, rax     \n"  // key
        "mov rsi, rbx     \n"  // msgflg
        "syscall"
    );

    // 20. `sys_msgsnd()`
    show_syscall(191, "sys_msgsnd");
    __asm__ (
        "mov rax, 191     \n"  // syscall number for sys_msgsnd
        "mov rdi, rax     \n"  // msqid
        "mov rsi, rbx     \n"  // msgp
        "mov rdx, rcx     \n"  // msgsz
        "mov r10, rbx     \n"  // msgflg
        "syscall"
    );

    // 21. `sys_msgrcv()`
    show_syscall(192, "sys_msgrcv");
    __asm__ (
        "mov rax, 192     \n"  // syscall number for sys_msgrcv
        "mov rdi, rax     \n"  // msqid
        "mov rsi, rbx     \n"  // msgp
        "mov rdx, rcx     \n"  // msgsz
        "mov r10, rbx     \n"  // msgtyp
        "syscall"
    );

    // 22. `sys_msgctl()`
    show_syscall(193, "sys_msgctl");
    __asm__ (
        "mov rax, 193     \n"  // syscall number for sys_msgctl
        "mov rdi, rax     \n"  // msqid
        "mov rsi, rbx     \n"  // cmd
        "mov rdx, rcx     \n"  // buf
        "syscall"
    );

    // 23. `sys_shmat()`
    show_syscall(194, "sys_shmat");
    __asm__ (
        "mov rax, 194     \n"  // syscall number for sys_shmat
        "mov rdi, rax     \n"  // shmid
        "mov rsi, rbx     \n"  // shmaddr
        "mov rdx, rcx     \n"  // shmflg
        "syscall"
    );

    // 24. `sys_shmctl()`
    show_syscall(195, "sys_shmctl");
    __asm__ (
        "mov rax, 195     \n"  // syscall number for sys_shmctl
        "mov rdi, rax     \n"  // shmid
        "mov rsi, rbx     \n"  // cmd
        "mov rdx, rcx     \n"  // buf
        "syscall"
    );

    // 25. `sys_shmdt()`
    show_syscall(196, "sys_shmdt");
    __asm__ (
        "mov rax, 196     \n"  // syscall number for sys_shmdt
        "mov rdi, rax     \n"  // shmaddr
        "syscall"
    );

    // 26. `sys_shmget()`
    show_syscall(197, "sys_shmget");
    __asm__ (
        "mov rax, 197     \n"  // syscall number for sys_shmget
        "mov rdi, rax     \n"  // key
        "mov rsi, rbx     \n"  // size
        "mov rdx, rcx     \n"  // shmflg
        "syscall"
    );

    // 27. `sys_socket()`
    show_syscall(281, "sys_socket");
    __asm__ (
        "mov rax, 281     \n"  // syscall number for sys_socket
        "mov rdi, rax     \n"  // domain
        "mov rsi, rbx     \n"  // type
        "mov rdx, rcx     \n"  // protocol
        "syscall"
    );

    // 28. `sys_connect()`
    show_syscall(282, "sys_connect");
    __asm__ (
        "mov rax, 282     \n"  // syscall number for sys_connect
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // addr
        "mov rdx, rcx     \n"  // addrlen
        "syscall"
    );

    // 29. `sys_bind()`
    show_syscall(283, "sys_bind");
    __asm__ (
        "mov rax, 283     \n"  // syscall number for sys_bind
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // addr
        "mov rdx, rcx     \n"  // addrlen
        "syscall"
    );

    // 30. `sys_listen()`
    show_syscall(284, "sys_listen");
    __asm__ (
        "mov rax, 284     \n"  // syscall number for sys_listen
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // backlog
        "syscall"
    );

    // 31. `sys_accept()`
    show_syscall(285, "sys_accept");
    __asm__ (
        "mov rax, 285     \n"  // syscall number for sys_accept
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // addr
        "mov rdx, rcx     \n"  // addrlen
        "syscall"
    );

    // 32. `sys_sendto()`
    show_syscall(286, "sys_sendto");
    __asm__ (
        "mov rax, 286     \n"  // syscall number for sys_sendto
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // buf
        "mov rdx, rcx     \n"  // len
        "mov r10, rbx     \n"  // flags
        "mov r8, rsi      \n"  // addr
        "mov r9, rdx      \n"  // addrlen
        "syscall"
    );

    // 33. `sys_recvfrom()`
    show_syscall(287, "sys_recvfrom");
    __asm__ (
        "mov rax, 287     \n"  // syscall number for sys_recvfrom
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // buf
        "mov rdx, rcx     \n"  // len
        "mov r10, rbx     \n"  // flags
        "mov r8, rsi      \n"  // addr
        "mov r9, rdx      \n"  // addrlen
        "syscall"
    );

    // 34. `sys_shutdown()`
    show_syscall(288, "sys_shutdown");
    __asm__ (
        "mov rax, 288     \n"  // syscall number for sys_shutdown
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // how
        "syscall"
    );

    // 35. `sys_setsockopt()`
    show_syscall(289, "sys_setsockopt");
    __asm__ (
        "mov rax, 289     \n"  // syscall number for sys_setsockopt
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // level
        "mov rdx, rcx     \n"  // optname
        "mov r10, rbx     \n"  // optval
        "mov r8, rdx      \n"  // optlen
        "syscall"
    );

    // 36. `sys_getsockopt()`
    show_syscall(290, "sys_getsockopt");
    __asm__ (
        "mov rax, 290     \n"  // syscall number for sys_getsockopt
        "mov rdi, rax     \n"  // fd
        "mov rsi, rbx     \n"  // level
        "mov rdx, rcx     \n"  // optname
        "mov r10, rbx     \n"  // optval
        "mov r8, rdx      \n"  // optlen
        "syscall"
    );

    // 37. `sys_getpwnam()`
    show_syscall(291, "sys_getpwnam");
    __asm__ (
        "mov rax, 291     \n"  // syscall number for sys_getpwnam
        "mov rdi, rax     \n"  // name
        "syscall"
    );

    // 38. `sys_getpwuid()`
    show_syscall(292, "sys_getpwuid");
    __asm__ (
        "mov rax, 292     \n"  // syscall number for sys_getpwuid
        "mov rdi, rax     \n"  // uid
        "syscall"
    );

    // 39. `sys_getuid()`
    show_syscall(24, "sys_getuid");
    __asm__ (
        "mov rax, 24      \n"  // syscall number for sys_getuid
        "syscall"
    );

    // 40. `sys_geteuid()`
    show_syscall(49, "sys_geteuid");
    __asm__ (
        "mov rax, 49      \n"  // syscall number for sys_geteuid
        "syscall"
    );

    // 41. `sys_getgid()`
    show_syscall(47, "sys_getgid");
    __asm__ (
        "mov rax, 47      \n"  // syscall number for sys_getgid
        "syscall"
    );

    // 42. `sys_getegid()`
    show_syscall(50, "sys_getegid");
    __asm__ (
        "mov rax, 50      \n"  // syscall number for sys_getegid
        "syscall"
    );

    // 43. `sys_setuid()`
    show_syscall(105, "sys_setuid");
    __asm__ (
        "mov rax, 105     \n"  // syscall number for sys_setuid
        "mov rdi, rax     \n"  // uid
        "syscall"
    );

    // 44. `sys_setgid()`
    show_syscall(106, "sys_setgid");
    __asm__ (
        "mov rax, 106     \n"  // syscall number for sys_setgid
        "mov rdi, rax     \n"  // gid
        "syscall"
    );

    // 45. `sys_seteuid()`
    show_syscall(107, "sys_seteuid");
    __asm__ (
        "mov rax, 107     \n"  // syscall number for sys_seteuid
        "mov rdi, rax     \n"  // euid
        "syscall"
    );

    // 46. `sys_setegid()`
    show_syscall(108, "sys_setegid");
    __asm__ (
        "mov rax, 108     \n"  // syscall number for sys_setegid
        "mov rdi, rax     \n"  // egid
        "syscall"
    );

    // 47. `sys_setpgid()`
    show_syscall(109, "sys_setpgid");
    __asm__ (
        "mov rax, 109     \n"  // syscall number for sys_setpgid
        "mov rdi, rax     \n"  // pid
        "mov rsi, rbx     \n"  // pgid
        "syscall"
    );

    // 48. `sys_setsid()`
    show_syscall(66, "sys_setsid");
    __asm__ (
        "mov rax, 66      \n"  // syscall number for sys_setsid
        "syscall"
    );

    // 49. `sys_setreuid()`
    show_syscall(70, "sys_setreuid");
    __asm__ (
        "mov rax, 70      \n"  // syscall number for sys_setreuid
        "mov rdi, rax     \n"  // ruid
        "mov rsi, rbx     \n"  // euid
        "syscall"
    );

    // 50. `sys_setregid()`
    show_syscall(71, "sys_setregid");
    __asm__ (
        "mov rax, 71      \n"  // syscall number for sys_setregid
        "mov rdi, rax     \n"  // rgid
        "mov rsi, rbx     \n"  // egid
        "syscall"
    );

    return 0;
}
