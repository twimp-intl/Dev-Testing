#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <elf.h>
#include <time.h>
#include <ctype.h>

#define RANDOM_NAME_LEN 12

// Function to generate a random 12-byte string
void generate_random_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < size - 1; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[size - 1] = '\0';
}

// Function to check if a file is a valid ELF file
int is_elf(FILE *file) {
    unsigned char magic[4];
    if (fread(magic, 1, 4, file) != 4) {
        return 0;
    }
    // Check ELF magic number
    return magic[0] == 0x7f && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F';
}

// Modify symbol table function and variable names
void modify_symbol_table(FILE *file, Elf64_Ehdr *ehdr, Elf64_Shdr *shdrs) {
    Elf64_Shdr *symtab = NULL, *strtab = NULL;
    Elf64_Sym *syms;
    char *strtab_data;
    size_t i;

    // Locate the .symtab and .strtab sections
    for (i = 0; i < ehdr->e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab = &shdrs[i];
        }
        if (shdrs[i].sh_type == SHT_STRTAB && strcmp(".strtab", (char *)(shdrs + ehdr->e_shstrndx + shdrs[i].sh_name)) == 0) {
            strtab = &shdrs[i];
        }
    }

    // If the symbol or string table is missing, exit
    if (!symtab || !strtab) {
        fprintf(stderr, "Warning: .symtab or .strtab section not found. Skipping modification.\n");
        return;
    }

    // Load the symbol and string table data
    syms = malloc(symtab->sh_size);
    strtab_data = malloc(strtab->sh_size);

    if (!syms || !strtab_data) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

    fseek(file, symtab->sh_offset, SEEK_SET);
    fread(syms, 1, symtab->sh_size, file);

    fseek(file, strtab->sh_offset, SEEK_SET);
    fread(strtab_data, 1, strtab->sh_size, file);

    // Modify function and variable names in the string table
    for (i = 0; i < symtab->sh_size / sizeof(Elf64_Sym); i++) {
        if (syms[i].st_name != 0 && (ELF64_ST_TYPE(syms[i].st_info) == STT_FUNC || ELF64_ST_TYPE(syms[i].st_info) == STT_OBJECT)) {
            char *name = &strtab_data[syms[i].st_name];
            if (isalpha(name[0])) {  // Only rename valid names
                printf("Original name: %s\n", name);  // Debug: Print original name
                generate_random_string(name, RANDOM_NAME_LEN);
                printf("New name: %s\n", name);        // Debug: Print new name
            }
        }
    }

    // Write the modified symbol and string tables back to the file
    fseek(file, symtab->sh_offset, SEEK_SET);
    fwrite(syms, 1, symtab->sh_size, file);

    fseek(file, strtab->sh_offset, SEEK_SET);
    fwrite(strtab_data, 1, strtab->sh_size, file);

    free(syms);
    free(strtab_data);
}

// Copy input file to output file
int copy_file(const char *src, const char *dst) {
    FILE *source = fopen(src, "rb");
    FILE *dest = fopen(dst, "wb");

    if (!source || !dest) {
        fprintf(stderr, "Error opening files for copying: %s\n", strerror(errno));
        return -1;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_input_file>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    char output_file[256];
    snprintf(output_file, sizeof(output_file), "%s.mod", input_file);

    // Copy the input file to output_file before modifying
    if (copy_file(input_file, output_file) != 0) {
        return 1;
    }

    FILE *file = fopen(output_file, "rb+");
    if (!file) {
        fprintf(stderr, "Error opening file %s: %s\n", output_file, strerror(errno));
        return 1;
    }

    // Check if it's a valid ELF file
    if (!is_elf(file)) {
        fprintf(stderr, "Error: %s is not a valid ELF file.\n", input_file);
        fclose(file);
        return 1;
    }

    // Read ELF header
    Elf64_Ehdr ehdr;
    if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr)) {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    // Read section headers
    Elf64_Shdr *shdrs = malloc(ehdr.e_shentsize * ehdr.e_shnum);
    if (!shdrs) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fseek(file, ehdr.e_shoff, SEEK_SET);
    fread(shdrs, 1, ehdr.e_shentsize * ehdr.e_shnum, file);

    // Modify function and variable names
    modify_symbol_table(file, &ehdr, shdrs);

    // Clean up
    fclose(file);
    free(shdrs);

    printf("Modified file saved as: %s\n", output_file);
    return 0;
}
