#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <errno.h>

// Function to show syscall details
void show_syscall(int syscall_number, const char *description) {
    printf("Syscall number: %d for %s\n", syscall_number, description);
}

int main() {
    printf("Demonstration of network-related syscalls and functions with assembly code:\n");

    // 1. `socket()`
    show_syscall(41, "sys_socket");
    __asm__ (
        "mov rax, 41      \n"  // syscall number for sys_socket
        "mov rdi, rbx     \n"  // domain
        "mov rsi, rcx     \n"  // type
        "mov rdx, r8      \n"  // protocol
        "syscall"
    );

    // 2. `bind()`
    show_syscall(49, "sys_bind");
    __asm__ (
        "mov rax, 49      \n"  // syscall number for sys_bind
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // address pointer
        "mov rdx, r8      \n"  // address length
        "syscall"
    );

    // 3. `listen()`
    show_syscall(50, "sys_listen");
    __asm__ (
        "mov rax, 50      \n"  // syscall number for sys_listen
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // backlog
        "syscall"
    );

    // 4. `accept()`
    show_syscall(43, "sys_accept");
    __asm__ (
        "mov rax, 43      \n"  // syscall number for sys_accept
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // address pointer
        "mov rdx, r8      \n"  // address length
        "syscall"
    );

    // 5. `connect()`
    show_syscall(42, "sys_connect");
    __asm__ (
        "mov rax, 42      \n"  // syscall number for sys_connect
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // address pointer
        "mov rdx, r8      \n"  // address length
        "syscall"
    );

    // 6. `send()`
    show_syscall(44, "sys_send");
    __asm__ (
        "mov rax, 44      \n"  // syscall number for sys_send
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // buffer pointer
        "mov rdx, r8      \n"  // length
        "mov r10, r9      \n"  // flags
        "syscall"
    );

    // 7. `recv()`
    show_syscall(45, "sys_recv");
    __asm__ (
        "mov rax, 45      \n"  // syscall number for sys_recv
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // buffer pointer
        "mov rdx, r8      \n"  // length
        "mov r10, r9      \n"  // flags
        "syscall"
    );

    // 8. `sendto()`
    show_syscall(50, "sys_sendto");
    __asm__ (
        "mov rax, 50      \n"  // syscall number for sys_sendto
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // buffer pointer
        "mov rdx, r8      \n"  // length
        "mov r10, r9      \n"  // flags
        "mov r11, r12     \n"  // address pointer
        "mov r12, r13     \n"  // address length
        "syscall"
    );

    // 9. `recvfrom()`
    show_syscall(51, "sys_recvfrom");
    __asm__ (
        "mov rax, 51      \n"  // syscall number for sys_recvfrom
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // buffer pointer
        "mov rdx, r8      \n"  // length
        "mov r10, r9      \n"  // flags
        "mov r11, r12     \n"  // address pointer
        "mov r12, r13     \n"  // address length
        "syscall"
    );

    // 10. `shutdown()`
    show_syscall(48, "sys_shutdown");
    __asm__ (
        "mov rax, 48      \n"  // syscall number for sys_shutdown
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // how
        "syscall"
    );

    // 11. `getsockopt()`
    show_syscall(55, "sys_getsockopt");
    __asm__ (
        "mov rax, 55      \n"  // syscall number for sys_getsockopt
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // option_name
        "mov r10, r9      \n"  // option_value
        "mov r11, r12     \n"  // option_len
        "syscall"
    );

    // 12. `setsockopt()`
    show_syscall(54, "sys_setsockopt");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_setsockopt
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // option_name
        "mov r10, r9      \n"  // option_value
        "mov r11, r12     \n"  // option_len
        "syscall"
    );

    // 13. `socketpair()`
    show_syscall(41, "sys_socketpair");
    __asm__ (
        "mov rax, 41      \n"  // syscall number for sys_socketpair
        "mov rdi, rbx     \n"  // domain
        "mov rsi, rcx     \n"  // type
        "mov rdx, r8      \n"  // protocol
        "mov r10, r9      \n"  // socket_fds pointer
        "syscall"
    );

    // 14. `getpeername()`
    show_syscall(52, "sys_getpeername");
    __asm__ (
        "mov rax, 52      \n"  // syscall number for sys_getpeername
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // address pointer
        "mov rdx, r8      \n"  // address length
        "syscall"
    );

    // 15. `getsockname()`
    show_syscall(53, "sys_getsockname");
    __asm__ (
        "mov rax, 53      \n"  // syscall number for sys_getsockname
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // address pointer
        "mov rdx, r8      \n"  // address length
        "syscall"
    );

    // 16. `poll()`
    show_syscall(7, "sys_poll");
    __asm__ (
        "mov rax, 7       \n"  // syscall number for sys_poll
        "mov rdi, rbx     \n"  // pollfd array
        "mov rsi, rcx     \n"  // number of descriptors
        "mov rdx, r8      \n"  // timeout
        "syscall"
    );

    // 17. `select()`
    show_syscall(102, "sys_select");
    __asm__ (
        "mov rax, 102     \n"  // syscall number for sys_select
        "mov rdi, rbx     \n"  // nfds
        "mov rsi, rcx     \n"  // readfds
        "mov rdx, r8      \n"  // writefds
        "mov r10, r9      \n"  // exceptfds
        "mov r11, r12     \n"  // timeout
        "syscall"
    );

    // 18. `ioctl()`
    show_syscall(54, "sys_ioctl");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_ioctl
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // request
        "mov rdx, r8      \n"  // argument
        "syscall"
    );

    // 19. `getifaddrs()`
    show_syscall(-1, "getifaddrs"); // Not a syscall, implemented as a library function
    // Assembly code is not applicable; use C library function
    printf("getifaddrs() is not a syscall, use C library function.\n");

    // 20. `sethostname()`
    show_syscall(64, "sys_sethostname");
    __asm__ (
        "mov rax, 64      \n"  // syscall number for sys_sethostname
        "mov rdi, rbx     \n"  // hostname pointer
        "mov rsi, rcx     \n"  // hostname length
        "syscall"
    );

    // 21. `gethostname()`
    show_syscall(63, "sys_gethostname");
    __asm__ (
        "mov rax, 63      \n"  // syscall number for sys_gethostname
        "mov rdi, rbx     \n"  // hostname pointer
        "mov rsi, rcx     \n"  // hostname length
        "syscall"
    );

    // 22. `getaddrinfo()`
    show_syscall(-1, "getaddrinfo"); // Not a syscall, implemented as a library function
    // Assembly code is not applicable; use C library function
    printf("getaddrinfo() is not a syscall, use C library function.\n");

    // 23. `freeaddrinfo()`
    show_syscall(-1, "freeaddrinfo"); // Not a syscall, implemented as a library function
    // Assembly code is not applicable; use C library function
    printf("freeaddrinfo() is not a syscall, use C library function.\n");

    // 24. `sendmsg()`
    show_syscall(46, "sys_sendmsg");
    __asm__ (
        "mov rax, 46      \n"  // syscall number for sys_sendmsg
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // message pointer
        "mov rdx, r8      \n"  // flags
        "syscall"
    );

    // 25. `recvmsg()`
    show_syscall(47, "sys_recvmsg");
    __asm__ (
        "mov rax, 47      \n"  // syscall number for sys_recvmsg
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // message pointer
        "mov rdx, r8      \n"  // flags
        "syscall"
    );

    // 26. `socket()`
    show_syscall(41, "sys_socket");
    __asm__ (
        "mov rax, 41      \n"  // syscall number for sys_socket
        "mov rdi, rbx     \n"  // domain
        "mov rsi, rcx     \n"  // type
        "mov rdx, r8      \n"  // protocol
        "syscall"
    );

    // 27. `getsockopt()`
    show_syscall(55, "sys_getsockopt");
    __asm__ (
        "mov rax, 55      \n"  // syscall number for sys_getsockopt
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // option_name
        "mov r10, r9      \n"  // option_value
        "mov r11, r12     \n"  // option_len
        "syscall"
    );

    // 28. `setsockopt()`
    show_syscall(54, "sys_setsockopt");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_setsockopt
        "mov rdi, rbx     \n"  // socket descriptor
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // option_name
        "mov r10, r9      \n"  // option_value
        "mov r11, r12     \n"  // option_len
        "syscall"
    );

    // 29. `ioctl()`
    show_syscall(54, "sys_ioctl");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_ioctl
        "mov rdi, rbx     \n"  // file descriptor
        "mov rsi, rcx     \n"  // request
        "mov rdx, r8      \n"  // argument
        "syscall"
    );

    // 30. `poll()`
    show_syscall(7, "sys_poll");
    __asm__ (
        "mov rax, 7       \n"  // syscall number for sys_poll
        "mov rdi, rbx     \n"  // pollfd array
        "mov rsi, rcx     \n"  // number of descriptors
        "mov rdx, r8      \n"  // timeout
        "syscall"
    );

    return 0;
}
