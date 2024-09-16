#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define KEY_SIZE 1024
#define MAX_DATA_SIZE 4096

// Substitution table (simple example, not secure)
void substitution(uint8_t *data, size_t length, uint8_t *key) {
    for (size_t i = 0; i < length; ++i) {
        data[i] = data[i] ^ key[i % KEY_SIZE]; // XOR substitution
    }
}

// Permutation function (simple example, not secure)
void permutation(uint8_t *data, size_t length) {
    for (size_t i = 0; i < length / 2; ++i) {
        uint8_t temp = data[i];
        data[i] = data[length - i - 1];
        data[length - i - 1] = temp;
    }
}

// Encrypt data
void encrypt(uint8_t *data, size_t length, uint8_t *key) {
    substitution(data, length, key);
    permutation(data, length);
}

// Decrypt data (same as encrypt due to XOR and reverse permutation)
void decrypt(uint8_t *data, size_t length, uint8_t *key) {
    permutation(data, length);
    substitution(data, length, key);
}

// Error handling
void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    uint8_t key[KEY_SIZE];
    uint8_t data[MAX_DATA_SIZE];
    size_t data_length;
    
    // Initialize key with some data
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = (uint8_t)i;
    }

    // Read input data
    printf("Enter data to encrypt (max 4096 bytes): ");
    if (fgets((char *)data, MAX_DATA_SIZE, stdin) == NULL) {
        handle_error("fgets failed");
    }

    data_length = strlen((char *)data);
    if (data_length == 0 || data_length > MAX_DATA_SIZE - 1) {
        handle_error("Invalid data length");
    }

    // Encrypt data
    encrypt(data, data_length, key);
    printf("Encrypted data: ");
    for (size_t i = 0; i < data_length; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");

    // Decrypt data
    decrypt(data, data_length, key);
    printf("Decrypted data: %s\n", data);

    return 0;
}
