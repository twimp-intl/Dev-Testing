#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// XOR key for encryption/decryption
#define XOR_KEY 0xAA

// Payload function to be "encrypted" and executed
void payload() {
    printf("Polymorphic Payload Executed\n");
}

// Function to encrypt/decrypt the payload using XOR
void xor_encrypt_decrypt(unsigned char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        data[i] ^= XOR_KEY;  // XOR each byte with the key
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Pointer to the payload function
    unsigned char *payload_ptr = (unsigned char *)payload;

    // Calculate the size of the payload function
    size_t payload_size = (size_t)main - (size_t)payload;

    // Allocate memory for the encrypted payload
    unsigned char *encrypted_payload = malloc(payload_size);
    if (!encrypted_payload) {
        perror("Memory allocation failed");
        return 1;
    }

    // Copy the original payload into the allocated memory
    memcpy(encrypted_payload, payload_ptr, payload_size);

    // Encrypt the payload using XOR encryption
    xor_encrypt_decrypt(encrypted_payload, payload_size);

    // Simulate polymorphic behavior by decrypting and running the payload
    for (int i = 0; i < 3; i++) {  // Simulate multiple executions with different "mutations"
        printf("Iteration %d:\n", i + 1);

        // Decrypt the payload back to its original form
        xor_encrypt_decrypt(encrypted_payload, payload_size);

        // Execute the decrypted payload (simulating execution)
        printf("Executing payload...\n");
        ((void (*)())encrypted_payload)();

        // Encrypt it again (mutating the code)
        xor_encrypt_decrypt(encrypted_payload, payload_size);

        // Optional: Simulate further mutation by modifying the XOR key slightly (polymorphism)
        XOR_KEY += rand() % 10; // Slightly changing the XOR key each iteration
    }

    free(encrypted_payload);
    return 0;
}
