#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>
#include <string.h>

// Function to show syscall details
void show_syscall(int syscall_number, const char *description) {
    printf("Syscall number: %d for %s\n", syscall_number, description);
}

int main() {
    printf("Demonstration of additional syscalls and functions with assembly code:\n");

    // 1. `socket()`
    show_syscall(41, "sys_socket");
    __asm__ (
        "mov rax, 41      \n"  // syscall number for sys_socket
        "mov rdi, rbx     \n"  // domain
        "mov rsi, rcx     \n"  // type
        "mov rdx, r8      \n"  // protocol
        "syscall"
    );

    // 2. `connect()`
    show_syscall(42, "sys_connect");
    __asm__ (
        "mov rax, 42      \n"  // syscall number for sys_connect
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 3. `accept()`
    show_syscall(43, "sys_accept");
    __asm__ (
        "mov rax, 43      \n"  // syscall number for sys_accept
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 4. `send()`
    show_syscall(44, "sys_send");
    __asm__ (
        "mov rax, 44      \n"  // syscall number for sys_send
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // buf
        "mov rdx, r8      \n"  // len
        "mov r10, r9      \n"  // flags
        "syscall"
    );

    // 5. `recv()`
    show_syscall(45, "sys_recv");
    __asm__ (
        "mov rax, 45      \n"  // syscall number for sys_recv
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // buf
        "mov rdx, r8      \n"  // len
        "mov r10, r9      \n"  // flags
        "syscall"
    );

    // 6. `sendto()`
    show_syscall(46, "sys_sendto");
    __asm__ (
        "mov rax, 46      \n"  // syscall number for sys_sendto
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // buf
        "mov rdx, r8      \n"  // len
        "mov r10, r9      \n"  // flags
        "mov r11, r12     \n"  // addr
        "mov r12, r13     \n"  // addrlen
        "syscall"
    );

    // 7. `recvfrom()`
    show_syscall(47, "sys_recvfrom");
    __asm__ (
        "mov rax, 47      \n"  // syscall number for sys_recvfrom
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // buf
        "mov rdx, r8      \n"  // len
        "mov r10, r9      \n"  // flags
        "mov r11, r12     \n"  // addr
        "mov r12, r13     \n"  // addrlen
        "syscall"
    );

    // 8. `shutdown()`
    show_syscall(48, "sys_shutdown");
    __asm__ (
        "mov rax, 48      \n"  // syscall number for sys_shutdown
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // how
        "syscall"
    );

    // 9. `bind()`
    show_syscall(49, "sys_bind");
    __asm__ (
        "mov rax, 49      \n"  // syscall number for sys_bind
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 10. `listen()`
    show_syscall(50, "sys_listen");
    __asm__ (
        "mov rax, 50      \n"  // syscall number for sys_listen
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // backlog
        "syscall"
    );

    // 11. `setsockopt()`
    show_syscall(54, "sys_setsockopt");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_setsockopt
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // optname
        "mov r10, r9      \n"  // optval
        "mov r11, r12     \n"  // optlen
        "syscall"
    );

    // 12. `getsockopt()`
    show_syscall(55, "sys_getsockopt");
    __asm__ (
        "mov rax, 55      \n"  // syscall number for sys_getsockopt
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // level
        "mov rdx, r8      \n"  // optname
        "mov r10, r9      \n"  // optval
        "mov r11, r12     \n"  // optlen
        "syscall"
    );

    // 13. `ioctl()`
    show_syscall(54, "sys_ioctl");
    __asm__ (
        "mov rax, 54      \n"  // syscall number for sys_ioctl
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // request
        "mov rdx, r8      \n"  // argp
        "syscall"
    );

    // 14. `select()`
    show_syscall(82, "sys_select");
    __asm__ (
        "mov rax, 82      \n"  // syscall number for sys_select
        "mov rdi, rbx     \n"  // nfds
        "mov rsi, rcx     \n"  // readfds
        "mov rdx, r8      \n"  // writefds
        "mov r10, r9      \n"  // exceptfds
        "mov r11, r12     \n"  // timeout
        "syscall"
    );

    // 15. `poll()`
    show_syscall(7, "sys_poll");
    __asm__ (
        "mov rax, 7       \n"  // syscall number for sys_poll
        "mov rdi, rbx     \n"  // fds
        "mov rsi, rcx     \n"  // nfds
        "mov rdx, r8      \n"  // timeout
        "syscall"
    );

    // 16. `epoll_create()`
    show_syscall(254, "sys_epoll_create");
    __asm__ (
        "mov rax, 254     \n"  // syscall number for sys_epoll_create
        "mov rdi, rbx     \n"  // size
        "syscall"
    );

    // 17. `epoll_ctl()`
    show_syscall(255, "sys_epoll_ctl");
    __asm__ (
        "mov rax, 255     \n"  // syscall number for sys_epoll_ctl
        "mov rdi, rbx     \n"  // epfd
        "mov rsi, rcx     \n"  // op
        "mov rdx, r8      \n"  // fd
        "mov r10, r9      \n"  // event
        "syscall"
    );

    // 18. `epoll_wait()`
    show_syscall(256, "sys_epoll_wait");
    __asm__ (
        "mov rax, 256     \n"  // syscall number for sys_epoll_wait
        "mov rdi, rbx     \n"  // epfd
        "mov rsi, rcx     \n"  // events
        "mov rdx, r8      \n"  // maxevents
        "mov r10, r9      \n"  // timeout
        "syscall"
    );

    // 19. `pipe()`
    show_syscall(22, "sys_pipe");
    __asm__ (
        "mov rax, 22      \n"  // syscall number for sys_pipe
        "mov rdi, rbx     \n"  // pipefd
        "syscall"
    );

    // 20. `socketpair()`
    show_syscall(53, "sys_socketpair");
    __asm__ (
        "mov rax, 53      \n"  // syscall number for sys_socketpair
        "mov rdi, rbx     \n"  // d
        "mov rsi, rcx     \n"  // type
        "mov rdx, r8      \n"  // protocol
        "mov r10, r9      \n"  // sv
        "syscall"
    );

    // 21. `shutdown()`
    show_syscall(48, "sys_shutdown");
    __asm__ (
        "mov rax, 48      \n"  // syscall number for sys_shutdown
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // how
        "syscall"
    );

    // 22. `accept4()`
    show_syscall(288, "sys_accept4");
    __asm__ (
        "mov rax, 288     \n"  // syscall number for sys_accept4
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "mov r10, r9      \n"  // flags
        "syscall"
    );

    // 23. `recvmmsg()`
    show_syscall(277, "sys_recvmmsg");
    __asm__ (
        "mov rax, 277     \n"  // syscall number for sys_recvmmsg
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // mmsg
        "mov rdx, r8      \n"  // vlen
        "mov r10, r9      \n"  // timeout
        "syscall"
    );

    // 24. `sendmmsg()`
    show_syscall(277, "sys_sendmmsg");
    __asm__ (
        "mov rax, 277     \n"  // syscall number for sys_sendmmsg
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // mmsg
        "mov rdx, r8      \n"  // vlen
        "syscall"
    );

    // 25. `sendfile()`
    show_syscall(40, "sys_sendfile");
    __asm__ (
        "mov rax, 40      \n"  // syscall number for sys_sendfile
        "mov rdi, rbx     \n"  // out_fd
        "mov rsi, rcx     \n"  // in_fd
        "mov rdx, r8      \n"  // offset
        "syscall"
    );

    // 26. `accept()`
    show_syscall(43, "sys_accept");
    __asm__ (
        "mov rax, 43      \n"  // syscall number for sys_accept
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 27. `getsockname()`
    show_syscall(115, "sys_getsockname");
    __asm__ (
        "mov rax, 115     \n"  // syscall number for sys_getsockname
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 28. `getpeername()`
    show_syscall(116, "sys_getpeername");
    __asm__ (
        "mov rax, 116     \n"  // syscall number for sys_getpeername
        "mov rdi, rbx     \n"  // sockfd
        "mov rsi, rcx     \n"  // addr
        "mov rdx, r8      \n"  // addrlen
        "syscall"
    );

    // 29. `sethostname()`
    show_syscall(170, "sys_sethostname");
    __asm__ (
        "mov rax, 170     \n"  // syscall number for sys_sethostname
        "mov rdi, rbx     \n"  // hostname
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 30. `setdomainname()`
    show_syscall(171, "sys_setdomainname");
    __asm__ (
        "mov rax, 171     \n"  // syscall number for sys_setdomainname
        "mov rdi, rbx     \n"  // domainname
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 31. `gethostname()`
    show_syscall(169, "sys_gethostname");
    __asm__ (
        "mov rax, 169     \n"  // syscall number for sys_gethostname
        "mov rdi, rbx     \n"  // hostname
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 32. `getdomainname()`
    show_syscall(164, "sys_getdomainname");
    __asm__ (
        "mov rax, 164     \n"  // syscall number for sys_getdomainname
        "mov rdi, rbx     \n"  // domainname
        "mov rsi, rcx     \n"  // len
        "syscall"
    );

    // 33. `fchdir()`
    show_syscall(33, "sys_fchdir");
    __asm__ (
        "mov rax, 33      \n"  // syscall number for sys_fchdir
        "mov rdi, rbx     \n"  // fd
        "syscall"
    );

    // 34. `fsync()`
    show_syscall(82, "sys_fsync");
    __asm__ (
        "mov rax, 82      \n"  // syscall number for sys_fsync
        "mov rdi, rbx     \n"  // fd
        "syscall"
    );

    // 35. `fdatasync()`
    show_syscall(148, "sys_fdatasync");
    __asm__ (
        "mov rax, 148     \n"  // syscall number for sys_fdatasync
        "mov rdi, rbx     \n"  // fd
        "syscall"
    );

    // 36. `link()`
    show_syscall(9, "sys_link");
    __asm__ (
        "mov rax, 9       \n"  // syscall number for sys_link
        "mov rdi, rbx     \n"  // oldpath
        "mov rsi, rcx     \n"  // newpath
        "syscall"
    );

    // 37. `unlink()`
    show_syscall(10, "sys_unlink");
    __asm__ (
        "mov rax, 10      \n"  // syscall number for sys_unlink
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 38. `rename()`
    show_syscall(38, "sys_rename");
    __asm__ (
        "mov rax, 38      \n"  // syscall number for sys_rename
        "mov rdi, rbx     \n"  // oldpath
        "mov rsi, rcx     \n"  // newpath
        "syscall"
    );

    // 39. `mkdir()`
    show_syscall(39, "sys_mkdir");
    __asm__ (
        "mov rax, 39      \n"  // syscall number for sys_mkdir
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 40. `rmdir()`
    show_syscall(40, "sys_rmdir");
    __asm__ (
        "mov rax, 40      \n"  // syscall number for sys_rmdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 41. `chmod()`
    show_syscall(90, "sys_chmod");
    __asm__ (
        "mov rax, 90      \n"  // syscall number for sys_chmod
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 42. `chown()`
    show_syscall(92, "sys_chown");
    __asm__ (
        "mov rax, 92      \n"  // syscall number for sys_chown
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // owner
        "mov rdx, r8      \n"  // group
        "syscall"
    );

    // 43. `umask()`
    show_syscall(60, "sys_umask");
    __asm__ (
        "mov rax, 60      \n"  // syscall number for sys_umask
        "mov rdi, rbx     \n"  // mask
        "syscall"
    );

    // 44. `stat()`
    show_syscall(4, "sys_stat");
    __asm__ (
        "mov rax, 4       \n"  // syscall number for sys_stat
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 45. `fstat()`
    show_syscall(5, "sys_fstat");
    __asm__ (
        "mov rax, 5       \n"  // syscall number for sys_fstat
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 46. `lstat()`
    show_syscall(6, "sys_lstat");
    __asm__ (
        "mov rax, 6       \n"  // syscall number for sys_lstat
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 47. `truncate()`
    show_syscall(92, "sys_truncate");
    __asm__ (
        "mov rax, 92      \n"  // syscall number for sys_truncate
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // length
        "syscall"
    );

    // 48. `ftruncate()`
    show_syscall(77, "sys_ftruncate");
    __asm__ (
        "mov rax, 77      \n"  // syscall number for sys_ftruncate
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // length
        "syscall"
    );

    // 49. `getcwd()`
    show_syscall(79, "sys_getcwd");
    __asm__ (
        "mov rax, 79      \n"  // syscall number for sys_getcwd
        "mov rdi, rbx     \n"  // buf
        "mov rsi, rcx     \n"  // size
        "syscall"
    );

    // 50. `chdir()`
    show_syscall(12, "sys_chdir");
    __asm__ (
        "mov rax, 12      \n"  // syscall number for sys_chdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    return 0;
}
