#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <libelf.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *elf_file = argv[1];
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "ELF library initialization failed.\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(elf_file, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    Elf *elf = elf_begin(fd, ELF_C_READ, NULL);
    if (!elf) {
        fprintf(stderr, "elf_begin() failed: %s.\n", elf_errmsg(-1));
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (elf_kind(elf) != ELF_K_ELF) {
        fprintf(stderr, "%s is not an ELF file.\n", elf_file);
        elf_end(elf);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Get the section header string table index
    size_t shstrndx;
    if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
        fprintf(stderr, "elf_getshdrstrndx() failed: %s.\n", elf_errmsg(-1));
        elf_end(elf);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Loop over all sections and print their names
    Elf_Scn *scn = NULL;
    Elf64_Shdr *shdr;  // Pointer to the section header
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        shdr = elf64_getshdr(scn);
        if (!shdr) {
            fprintf(stderr, "elf64_getshdr() failed: %s.\n", elf_errmsg(-1));
            continue;
        }
        const char *name = elf_strptr(elf, shstrndx, shdr->sh_name);
        printf("Section name: %s\n", name);
    }

    elf_end(elf);
    close(fd);
    return 0;
}
