#include <sys/utsname.h>
#include <stdio.h>

int main() {
    struct utsname info;
    if (uname(&info) == 0) {
        printf("System name: %s\n", info.sysname);
        printf("Node name: %s\n", info.nodename);
        printf("Release: %s\n", info.release);
        printf("Version: %s\n", info.version);
        printf("Machine: %s\n", info.machine);
    } else {
        perror("uname");
    }
    return 0;
}
