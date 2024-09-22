#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <errno.h>

#define FUNC_PROLOGUE_SIZE 16

int is_function_prologue(unsigned char *code) {
    // Simple heuristic for detecting function prologue
    // This is just an example. Real prologues can vary.
    return (code[0] == 0x55 ||  // push   %rbp
            (code[0] == 0x48 && code[1] == 0x89 && code[2] == 0xe5)); // mov    %rsp,%rbp
}

void list_function_starts(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    Elf64_Ehdr ehdr;
    if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr)) {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        fclose(file);
        return;
    }

    // Verify ELF magic number
    if (ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || 
        ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F') {
        fprintf(stderr, "Error: %s is not a valid ELF file.\n", filename);
        fclose(file);
        return;
    }

    // Read the entire file into memory
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *file_data = malloc(file_size);
    if (!file_data) {
        fprintf(stderr, "Error allocating memory for file data: %s\n", strerror(errno));
        fclose(file);
        return;
    }
    
    fread(file_data, 1, file_size, file);

    printf("Detected function starts in %s:\n", filename);
    for (long i = 0; i < file_size - FUNC_PROLOGUE_SIZE; i++) {
        if (is_function_prologue(&file_data[i])) {
            printf("Possible function start at: 0x%lx\n", i);
        }
    }

    free(file_data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <elf_binary_file>\n", argv[0]);
        return 1;
    }

    list_function_starts(argv[1]);
    return 0;
}
