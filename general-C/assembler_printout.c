#include <stdio.h>
#include <stdlib.h>

// Function to write the MOV instruction (64-bit immediate to rax)
void encode_mov_rax_imm64(long long value, FILE *output) {
    unsigned char opcode = 0x48; // REX prefix for 64-bit register
    unsigned char opcode2 = 0xB8; // Opcode for MOV rax, imm64
    fwrite(&opcode, 1, 1, output);
    fwrite(&opcode2, 1, 1, output);
    fwrite(&value, 8, 1, output); // Write the 64-bit immediate value in little-endian
}

// Function to write the ADD instruction (add 64-bit immediate to rax)
void encode_add_rax_imm64(long long value, FILE *output) {
    unsigned char opcode = 0x48; // REX prefix for 64-bit register
    unsigned char opcode2[2] = {0x81, 0xC0}; // Opcode for ADD rax, imm64
    fwrite(&opcode, 1, 1, output);
    fwrite(opcode2, 1, 2, output);
    fwrite(&value, 8, 1, output); // Write the 64-bit immediate value
}

// Function to write the SUB instruction (subtract 64-bit immediate from rax)
void encode_sub_rax_imm64(long long value, FILE *output) {
    unsigned char opcode = 0x48; // REX prefix for 64-bit register
    unsigned char opcode2[2] = {0x81, 0xE8}; // Opcode for SUB rax, imm64
    fwrite(&opcode, 1, 1, output);
    fwrite(opcode2, 1, 2, output);
    fwrite(&value, 8, 1, output); // Write the 64-bit immediate value
}

// Function to write JMP (jmp to 64-bit relative offset)
void encode_jmp_rel64(long long offset, FILE *output) {
    unsigned char opcode = 0xE9; // Opcode for JMP rel32 (64-bit needs 64-bit address calculation)
    fwrite(&opcode, 1, 1, output);
    fwrite(&offset, 8, 1, output); // Write the 64-bit relative offset
}

// Function to write CALL (call to 64-bit relative offset)
void encode_call_rel64(long long offset, FILE *output) {
    unsigned char opcode = 0xE8; // Opcode for CALL rel32 (64-bit needs 64-bit address calculation)
    fwrite(&opcode, 1, 1, output);
    fwrite(&offset, 8, 1, output); // Write the 64-bit relative offset
}

// Function to write a NOP (No Operation) instruction
void encode_nop(FILE *output) {
    unsigned char opcode = 0x90; // Opcode for NOP
    fwrite(&opcode, 1, 1, output);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: assembler <output.bin>\n");
        return 1;
    }

    FILE *output = fopen(argv[1], "wb");
    if (!output) {
        printf("Error opening output file\n");
        return 1;
    }

    // Example usage of predefined templates:
    
    // MOV rax, 1234567890123456789
    encode_mov_rax_imm64(1234567890123456789LL, output);

    // ADD rax, 9876543210
    encode_add_rax_imm64(9876543210LL, output);

    // SUB rax, 1234567890
    encode_sub_rax_imm64(1234567890LL, output);

    // NOP (no operation)
    encode_nop(output);

    // JMP forward by 100 bytes (relative address)
    encode_jmp_rel64(100LL, output);

    // CALL forward by 200 bytes (relative address)
    encode_call_rel64(200LL, output);

    fclose(output);
    printf("Assembly complete!\n");

    return 0;
}
