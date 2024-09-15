#include <stdio.h>

int main() {
    // 1. `reboot()`
    show_syscall(88, "sys_reboot");
    __asm__ (
        "mov rax, 88      \n"  // syscall number for sys_reboot
        "mov rdi, rbx     \n"  // cmd
        "mov rsi, rcx     \n"  // arg1
        "mov rdx, r8      \n"  // arg2
        "mov r10, r9      \n"  // arg3
        "syscall"
    );

    // 2. `syslog()`
    show_syscall(103, "sys_syslog");
    __asm__ (
        "mov rax, 103     \n"  // syscall number for sys_syslog
        "mov rdi, rbx     \n"  // type
        "mov rsi, rcx     \n"  // buf
        "mov rdx, r8      \n"  // len
        "mov r10, r9      \n"  // facility
        "syscall"
    );

    // 3. `wait4()`
    show_syscall(114, "sys_wait4");
    __asm__ (
        "mov rax, 114     \n"  // syscall number for sys_wait4
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // status
        "mov rdx, r8      \n"  // options
        "mov r10, r9      \n"  // ru
        "syscall"
    );

    // 4. `prctl()`
    show_syscall(157, "sys_prctl");
    __asm__ (
        "mov rax, 157     \n"  // syscall number for sys_prctl
        "mov rdi, rbx     \n"  // option
        "mov rsi, rcx     \n"  // arg2
        "mov rdx, r8      \n"  // arg3
        "mov r10, r9      \n"  // arg4
        "mov r11, r12     \n"  // arg5
        "syscall"
    );

    // 5. `personality()`
    show_syscall(135, "sys_personality");
    __asm__ (
        "mov rax, 135     \n"  // syscall number for sys_personality
        "mov rdi, rbx     \n"  // persona
        "syscall"
    );

    // 6. `setrlimit()`
    show_syscall(162, "sys_setrlimit");
    __asm__ (
        "mov rax, 162     \n"  // syscall number for sys_setrlimit
        "mov rdi, rbx     \n"  // resource
        "mov rsi, rcx     \n"  // rlim
        "syscall"
    );

    // 7. `getrlimit()`
    show_syscall(169, "sys_getrlimit");
    __asm__ (
        "mov rax, 169     \n"  // syscall number for sys_getrlimit
        "mov rdi, rbx     \n"  // resource
        "mov rsi, rcx     \n"  // rlim
        "syscall"
    );

    // 8. `getrusage()`
    show_syscall(102, "sys_getrusage");
    __asm__ (
        "mov rax, 102     \n"  // syscall number for sys_getrusage
        "mov rdi, rbx     \n"  // who
        "mov rsi, rcx     \n"  // usage
        "syscall"
    );

    // 9. `sysinfo()`
    show_syscall(99, "sys_sysinfo");
    __asm__ (
        "mov rax, 99      \n"  // syscall number for sys_sysinfo
        "mov rdi, rbx     \n"  // info
        "syscall"
    );

    // 10. `uname()`
    show_syscall(63, "sys_uname");
    __asm__ (
        "mov rax, 63      \n"  // syscall number for sys_uname
        "mov rdi, rbx     \n"  // buf
        "syscall"
    );

    // 11. `fstat()`
    show_syscall(5, "sys_fstat");
    __asm__ (
        "mov rax, 5       \n"  // syscall number for sys_fstat
        "mov rdi, rbx     \n"  // fd
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 12. `stat()`
    show_syscall(4, "sys_stat");
    __asm__ (
        "mov rax, 4       \n"  // syscall number for sys_stat
        "mov rdi, rbx     \n"  // filename
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 13. `lstat()`
    show_syscall(6, "sys_lstat");
    __asm__ (
        "mov rax, 6       \n"  // syscall number for sys_lstat
        "mov rdi, rbx     \n"  // filename
        "mov rsi, rcx     \n"  // statbuf
        "syscall"
    );

    // 14. `access()`
    show_syscall(21, "sys_access");
    __asm__ (
        "mov rax, 21      \n"  // syscall number for sys_access
        "mov rdi, rbx     \n"  // filename
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 15. `unlink()`
    show_syscall(10, "sys_unlink");
    __asm__ (
        "mov rax, 10      \n"  // syscall number for sys_unlink
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 16. `rename()`
    show_syscall(38, "sys_rename");
    __asm__ (
        "mov rax, 38      \n"  // syscall number for sys_rename
        "mov rdi, rbx     \n"  // oldname
        "mov rsi, rcx     \n"  // newname
        "syscall"
    );

    // 17. `link()`
    show_syscall(9, "sys_link");
    __asm__ (
        "mov rax, 9       \n"  // syscall number for sys_link
        "mov rdi, rbx     \n"  // oldname
        "mov rsi, rcx     \n"  // newname
        "syscall"
    );

    // 18. `mkdir()`
    show_syscall(39, "sys_mkdir");
    __asm__ (
        "mov rax, 39      \n"  // syscall number for sys_mkdir
        "mov rdi, rbx     \n"  // pathname
        "mov rsi, rcx     \n"  // mode
        "syscall"
    );

    // 19. `rmdir()`
    show_syscall(40, "sys_rmdir");
    __asm__ (
        "mov rax, 40      \n"  // syscall number for sys_rmdir
        "mov rdi, rbx     \n"  // pathname
        "syscall"
    );

    // 20. `getuid()`
    show_syscall(102, "sys_getuid");
    __asm__ (
        "mov rax, 102     \n"  // syscall number for sys_getuid
        "syscall"
    );

    // 21. `geteuid()`
    show_syscall(107, "sys_geteuid");
    __asm__ (
        "mov rax, 107     \n"  // syscall number for sys_geteuid
        "syscall"
    );

    // 22. `getgid()`
    show_syscall(104, "sys_getgid");
    __asm__ (
        "mov rax, 104     \n"  // syscall number for sys_getgid
        "syscall"
    );

    // 23. `getegid()`
    show_syscall(108, "sys_getegid");
    __asm__ (
        "mov rax, 108     \n"  // syscall number for sys_getegid
        "syscall"
    );

    // 24. `setuid()`
    show_syscall(105, "sys_setuid");
    __asm__ (
        "mov rax, 105     \n"  // syscall number for sys_setuid
        "mov rdi, rbx     \n"  // uid
        "syscall"
    );

    // 25. `setgid()`
    show_syscall(106, "sys_setgid");
    __asm__ (
        "mov rax, 106     \n"  // syscall number for sys_setgid
        "mov rdi, rbx     \n"  // gid
        "syscall"
    );

    // 26. `seteuid()`
    show_syscall(106, "sys_seteuid");
    __asm__ (
        "mov rax, 106     \n"  // syscall number for sys_seteuid
        "mov rdi, rbx     \n"  // euid
        "syscall"
    );

    // 27. `setegid()`
    show_syscall(107, "sys_setegid");
    __asm__ (
        "mov rax, 107     \n"  // syscall number for sys_setegid
        "mov rdi, rbx     \n"  // egid
        "syscall"
    );

    // 28. `setpgid()`
    show_syscall(109, "sys_setpgid");
    __asm__ (
        "mov rax, 109     \n"  // syscall number for sys_setpgid
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // pgid
        "syscall"
    );

    // 29. `getpgrp()`
    show_syscall(110, "sys_getpgrp");
    __asm__ (
        "mov rax, 110     \n"  // syscall number for sys_getpgrp
        "syscall"
    );

    // 30. `setsid()`
    show_syscall(111, "sys_setsid");
    __asm__ (
        "mov rax, 111     \n"  // syscall number for sys_setsid
        "syscall"
    );

    // 31. `setrlimit()`
    show_syscall(162, "sys_setrlimit");
    __asm__ (
        "mov rax, 162     \n"  // syscall number for sys_setrlimit
        "mov rdi, rbx     \n"  // resource
        "mov rsi, rcx     \n"  // rlim
        "syscall"
    );

    // 32. `getrlimit()`
    show_syscall(169, "sys_getrlimit");
    __asm__ (
        "mov rax, 169     \n"  // syscall number for sys_getrlimit
        "mov rdi, rbx     \n"  // resource
        "mov rsi, rcx     \n"  // rlim
        "syscall"
    );

    // 33. `settimeofday()`
    show_syscall( clockid_t show_syscall;
  // syscall number for sys_settimeofday
        "mov rdi, rbx     \n"  // timeval
        "mov rsi, rcx     \n"  // tz
        "syscall"
    );

    // 34. `gettimeofday()`
    show_syscall(96, "sys_gettimeofday");
    __asm__ (
        "mov rax, 96      \n"  // syscall number for sys_gettimeofday
        "mov rdi, rbx     \n"  // timeval
        "mov rsi, rcx     \n"  // tz
        "syscall"
    );

    // 35. `clock_gettime()`
    show_syscall(228, "sys_clock_gettime");
    __asm__ (
        "mov rax, 228     \n"  // syscall number for sys_clock_gettime
        "mov rdi, rbx     \n"  // clk_id
        "mov rsi, rcx     \n"  // tp
        "syscall"
    );

    // 36. `clock_settime()`
    show_syscall(229, "sys_clock_settime");
    __asm__ (
        "mov rax, 229     \n"  // syscall number for sys_clock_settime
        "mov rdi, rbx     \n"  // clk_id
        "mov rsi, rcx     \n"  // tp
        "syscall"
    );

    // 37. `clock_getres()`
    show_syscall(230, "sys_clock_getres");
    __asm__ (
        "mov rax, 230     \n"  // syscall number for sys_clock_getres
        "mov rdi, rbx     \n"  // clk_id
        "mov rsi, rcx     \n"  // res
        "syscall"
    );

    // 38. `timer_create()`
    show_syscall(243, "sys_timer_create");
    __asm__ (
        "mov rax, 243     \n"  // syscall number for sys_timer_create
        "mov rdi, rbx     \n"  // clockid
        "mov rsi, rcx     \n"  // evp
        "mov rdx, r8      \n"  // timerid
        "syscall"
    );

    // 39. `timer_settime()`
    show_syscall(244, "sys_timer_settime");
    __asm__ (
        "mov rax, 244     \n"  // syscall number for sys_timer_settime
        "mov rdi, rbx     \n"  // timerid
        "mov rsi, rcx     \n"  // flags
        "mov rdx, r8      \n"  // new_value
        "mov r10, r9      \n"  // old_value
        "syscall"
    );

    // 40. `timer_gettime()`
    show_syscall(245, "sys_timer_gettime");
    __asm__ (
        "mov rax, 245     \n"  // syscall number for sys_timer_gettime
        "mov rdi, rbx     \n"  // timerid
        "mov rsi, rcx     \n"  // curr_value
        "syscall"
    );

    // 41. `timer_delete()`
    show_syscall(246, "sys_timer_delete");
    __asm__ (
        "mov rax, 246     \n"  // syscall number for sys_timer_delete
        "mov rdi, rbx     \n"  // timerid
        "syscall"
    );

    // 42. `sched_getscheduler()`
    show_syscall(159, "sys_sched_getscheduler");
    __asm__ (
        "mov rax, 159     \n"  // syscall number for sys_sched_getscheduler
        "mov rdi, rbx     \n"  // pid
        "syscall"
    );

    // 43. `sched_setscheduler()`
    show_syscall(156, "sys_sched_setscheduler");
    __asm__ (
        "mov rax, 156     \n"  // syscall number for sys_sched_setscheduler
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // policy
        "mov rdx, r8      \n"  // param
        "syscall"
    );

    // 44. `sched_getparam()`
    show_syscall(153, "sys_sched_getparam");
    __asm__ (
        "mov rax, 153     \n"  // syscall number for sys_sched_getparam
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // param
        "syscall"
    );

    // 45. `sched_setparam()`
    show_syscall(154, "sys_sched_setparam");
    __asm__ (
        "mov rax, 154     \n"  // syscall number for sys_sched_setparam
        "mov rdi, rbx     \n"  // pid
        "mov rsi, rcx     \n"  // param
        "syscall"
    );

    // 46. `sched_yield()`
    show_syscall(158, "sys_sched_yield");
    __asm__ (
        "mov rax, 158     \n"  // syscall number for sys_sched_yield
        "syscall"
    );

    // 47. `sched_get_priority_max()`
    show_syscall(141, "sys_sched_get_priority_max");
    __asm__ (
        "mov rax, 141     \n"  // syscall number for sys_sched_get_priority_max
        "mov rdi, rbx     \n"  // policy
        "syscall"
    );

    // 48. `sched_get_priority_min()`
    show_syscall(142, "sys_sched_get_priority_min");
    __asm__ (
        "mov rax, 142     \n"  // syscall number for sys_sched_get_priority_min
        "mov rdi, rbx     \n"  // policy
        "syscall"
    );

    // 49. `sys_getpgid()`
    show_syscall(132, "sys_getpgid");
    __asm__ (
        "mov rax, 132     \n"  // syscall number for sys_getpgid
        "mov rdi, rbx     \n"  // pid
        "syscall"
    );

    // 50. `sys_getsid()`
    show_syscall(147, "sys_getsid");
    __asm__ (
        "mov rax, 147     \n"  // syscall number for sys_getsid
        "mov rdi, rbx     \n"  // pid
        "syscall"
    );

    return 0;
}
