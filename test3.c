#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  // Include this header for open(), O_RDWR, O_CREAT
#include <sys/types.h>
#include <sys/stat.h>

int return(int return_num) {
printf("test");
}

void main() {
return 1;
}
