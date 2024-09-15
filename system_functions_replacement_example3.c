#include <stdio.h>

int main() {
    // 1. `mprotect()`
    show_syscall(10, "sys_mprotect");
    __asm__ (
        "mov rax, 10      \n"  // syscall number for sys_mprotect
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // len
        "mov rdx, r8      \n"  // prot
        "syscall"
    );

    // 2. `mlock()`
    show_syscall(14, "sys_mlock");
    __asm__ (
        "mov rax, 14      \n"  // syscall number for sys_mlock
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 3. `munlock()`
    show_syscall(15, "sys_munlock");
    __asm__ (
        "mov rax, 15      \n"  // syscall number for sys_munlock
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 4. `munlockall()`
    show_syscall(16, "sys_munlockall");
    __asm__ (
        "mov rax, 16      \n"  // syscall number for sys_munlockall
        "syscall"
    );

    // 5. `msync()`
    show_syscall(25, "sys_msync");
    __asm__ (
        "mov rax, 25      \n"  // syscall number for sys_msync
        "mov rdi, rbx     \n"  // addr
        "mov rsi, rcx     \n"  // len
        "mov rdx, r8      \n"  // flags
        "syscall"
    );

    // 6. `shmget()`
    show_syscall(29, "sys_shmget");
    __asm__ (
        "mov rax, 29      \n"  // syscall number for sys_shmget
        "mov rdi, rbx     \n"  // key
        "mov rsi, rcx     \n"  // size
        "mov rdx, r8      \n"  // shmflg
        "syscall"
    );

    // 7. `shmat()`
    show_syscall(30, "sys_shmat");
    __asm__ (
        "mov rax, 30      \n"  // syscall number for sys_shmat
        "mov rdi, rbx     \n"  // shmid
        "mov rsi, rcx     \n"  // shmaddr
        "mov rdx, r8      \n"  // shmflg
        "syscall"
    );

    // 8. `shmctl()`
    show_syscall(31, "sys_shmctl");
    __asm__ (
        "mov rax, 31      \n"  // syscall number for sys_shmctl
        "mov rdi, rbx     \n"  // shmid
        "mov rsi, rcx     \n"  // cmd
        "mov rdx, r8      \n"  // buf
        "syscall"
    );

    // 9. `semget()`
    show_syscall(32, "sys_semget");
    __asm__ (
        "mov rax, 32      \n"  // syscall number for sys_semget
        "mov rdi, rbx     \n"  // key
        "mov rsi, rcx     \n"  // nsems
        "mov rdx, r8      \n"  // semflg
        "syscall"
    );

    // 10. `semop()`
    show_syscall(33, "sys_semop");
    __asm__ (
        "mov rax, 33      \n"  // syscall number for sys_semop
        "mov rdi, rbx     \n"  // semid
        "mov rsi, rcx     \n"  // semops
        "mov rdx, r8      \n"  // numops
        "syscall"
    );

    // 11. `semctl()`
    show_syscall(34, "sys_semctl");
    __asm__ (
        "mov rax, 34      \n"  // syscall number for sys_semctl
        "mov rdi, rbx     \n"  // semid
        "mov rsi, rcx     \n"  // semnum
        "mov rdx, r8      \n"  // cmd
        "mov r10, r9      \n"  // arg
        "syscall"
    );

    // 12. `msgget()`
    show_syscall(35, "sys_msgget");
    __asm__ (
        "mov rax, 35      \n"  // syscall number for sys_msgget
        "mov rdi, rbx     \n"  // key
        "mov rsi, rcx     \n"  // msgflg
        "syscall"
    );

    // 13. `msgsnd()`
    show_syscall(36, "sys_msgsnd");
    __asm__ (
        "mov rax, 36      \n"  // syscall number for sys_msgsnd
        "mov rdi, rbx     \n"  // msqid
        "mov rsi, rcx     \n"  // msgp
        "mov rdx, r8      \n"  // msgsz
        "mov r10, r9      \n"  // msgflg
        "syscall"
    );

    // 14. `msgrcv()`
    show_syscall(37, "sys_msgrcv");
    __asm__ (
        "mov rax, 37      \n"  // syscall number for sys_msgrcv
        "mov rdi, rbx     \n"  // msqid
        "mov rsi, rcx     \n"  // msgp
        "mov rdx, r8      \n"  // msgsz
        "mov r10, r9      \n"  // msgtyp
        "mov r11, rdi     \n"  // msgflg
        "syscall"
    );

    // 15. `msgctl()`
    show_syscall(38, "sys_msgctl");
    __asm__ (
        "mov rax, 38      \n"  // syscall number for sys_msgctl
        "mov rdi, rbx     \n"  // msqid
        "mov rsi, rcx     \n"  // cmd
        "mov rdx, r8      \n"  // buf
        "syscall"
    );

    // 16. `getdents()`
    show_syscall(78, "sys_getdents");
    __asm__ (
        "mov rax, 78      \n"  // syscall number for sys_getdents
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // dirp
        "mov rdx, r8      \n"  // count
        "syscall"
    );

    // 17. `getcwd()`
    show_syscall(79, "sys_getcwd");
    __asm__ (
        "mov rax, 79      \n"  // syscall number for sys_getcwd
        "mov rdi, rbx     \n"  // buf
        "mov rsi, rcx     \n"  // size
        "syscall"
    );

    // 18. `chdir()`
    show_syscall(12, "sys_chdir");
    __asm__ (
        "mov rax, 12      \n"  // syscall number for sys_chdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 19. `fchdir()`
    show_syscall(33, "sys_fchdir");
    __asm__ (
        "mov rax, 33      \n"  // syscall number for sys_fchdir
        "mov rdi, rbx     \n"  // fd
        "syscall"
    );

    // 20. `chroot()`
    show_syscall(61, "sys_chroot");
    __asm__ (
        "mov rax, 61      \n"  // syscall number for sys_chroot
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 21. `pivot_root()`
    show_syscall(155, "sys_pivot_root");
    __asm__ (
        "mov rax, 
