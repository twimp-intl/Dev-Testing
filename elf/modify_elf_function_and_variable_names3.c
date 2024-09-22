#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <elf.h>
#include <time.h>
#include <ctype.h>

#define RANDOM_NAME_LEN 12
#define GCC_SEARCH "GCC: ("

// Function to generate random replacements using '1', 'l', '0', 'O'
void randomize_name(char *name) {
    const char replacements[] = "1l0O";
    size_t len = strlen(name);
    for (size_t i = 0; i < len; i++) {
        if (isalnum(name[i])) {
            int key = rand() % 4;
            name[i] = replacements[key];
        }
    }
}

// Function to randomize a GCC string after "GCC: ("
void randomize_gcc_string(char *gcc_string) {
    char *p = gcc_string + strlen(GCC_SEARCH);
    while (*p != '\0') {
        if (isalpha(*p)) {
            *p = 'a' + rand() % 26;  // Random letter
        } else if (isdigit(*p)) {
            *p = '0' + rand() % 10;  // Random digit
        } else if (*p == ')') {
            break;
        }
        p++;
    }
}

// Function to check if a file is a valid ELF file
int is_elf(FILE *file) {
    unsigned char magic[4];
    if (fread(magic, 1, 4, file) != 4) {
        return 0;
    }
    return magic[0] == 0x7f && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F';
}

// Modify symbol table function and variable names
void modify_symbol_table(FILE *file, Elf64_Ehdr *ehdr, Elf64_Shdr *shdrs, char *file_data, size_t file_size) {
    Elf64_Shdr *symtab = NULL, *strtab = NULL;
    Elf64_Sym *syms;
    char *strtab_data;
    size_t i;

    for (i = 0; i < ehdr->e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab = &shdrs[i];
        }
        if (shdrs[i].sh_type == SHT_STRTAB && strcmp(".strtab", (char *)(shdrs + ehdr->e_shstrndx + shdrs[i].sh_name)) == 0) {
            strtab = &shdrs[i];
        }
    }

    if (!symtab || !strtab) {
        fprintf(stderr, "Warning: .symtab or .strtab section not found. Skipping modification.\n");
        return;
    }

    syms = malloc(symtab->sh_size);
    strtab_data = malloc(strtab->sh_size);

    if (!syms || !strtab_data) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(syms);
        free(strtab_data);
        return;
    }

    fseek(file, symtab->sh_offset, SEEK_SET);
    fread(syms, 1, symtab->sh_size, file);

    fseek(file, strtab->sh_offset, SEEK_SET);
    fread(strtab_data, 1, strtab->sh_size, file);

    for (i = 0; i < symtab->sh_size / sizeof(Elf64_Sym); i++) {
        if (syms[i].st_name != 0 && ELF64_ST_TYPE(syms[i].st_info) == STT_FUNC) {
            char *name = &strtab_data[syms[i].st_name];
            char original_name[256];
            strcpy(original_name, name);

            randomize_name(name);
            printf("Original Function Name: %s, Randomized: %s\n", original_name, name); // Debug output

            for (size_t j = 0; j < file_size - strlen(original_name); j++) {
                if (memcmp(&file_data[j], original_name, strlen(original_name)) == 0) {
                    memcpy(&file_data[j], name, strlen(name));
                }
            }
        }
    }

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
        if (source) fclose(source);
        if (dest) fclose(dest);
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

    if (copy_file(input_file, output_file) != 0) {
        return 1;
    }

    FILE *file = fopen(output_file, "rb+");
    if (!file) {
        fprintf(stderr, "Error opening file %s: %s\n", output_file, strerror(errno));
        return 1;
    }

    if (!is_elf(file)) {
        fprintf(stderr, "Error: %s is not a valid ELF file.\n", input_file);
        fclose(file);
        return 1;
    }

    Elf64_Ehdr ehdr;
    if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr)) {
        fprintf(stderr, "Error: Failed to read full ELF header.\n");
        fclose(file);
        return 1;
    }

    size_t file_size = ftell(file);
    if (file_size == (size_t)-1) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    char *file_data = malloc(file_size);
    if (!file_data) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    fseek(file, 0, SEEK_SET);
    fread(file_data, 1, file_size, file);

    Elf64_Shdr *shdrs = malloc(ehdr.e_shentsize * ehdr.e_shnum);
    if (!shdrs) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(file_data);
        fclose(file);
        return 1;
    }

    fseek(file, ehdr.e_shoff, SEEK_SET);
    fread(shdrs, 1, ehdr.e_shentsize * ehdr.e_shnum, file);

    // Modify function names and variable names
    modify_symbol_table(file, &ehdr, shdrs, file_data, file_size);

    // Modify GCC version string
    char *gcc_string = strstr(file_data, GCC_SEARCH);
    if (gcc_string) {
        randomize_gcc_string(gcc_string);
        printf("Modified GCC String: %s\n", gcc_string); // Debug output
    }

    fseek(file, 0, SEEK_SET);
    fwrite(file_data, 1, file_size, file);

    free(file_data);
    free(shdrs);
    fclose(file);

    printf("Modification completed. Output written to %s\n", output_file);
    return 0;
}
