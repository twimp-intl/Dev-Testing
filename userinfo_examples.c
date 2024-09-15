#include <pwd.h>
#include <stdio.h>

int main() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("User name: %s\n", pw->pw_name);
        printf("Home directory: %s\n", pw->pw_dir);
    } else {
        perror("getpwuid");
    }
    return 0;
}
