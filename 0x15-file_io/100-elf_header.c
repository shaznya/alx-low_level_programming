#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type);
void print_entry(unsigned long int e_entry);

void print_elf_header(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Can't read file %s\n", filename);
        exit(98);
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr)) {
        close(fd);
        fprintf(stderr, "Error: Failed to read ELF header\n");
        exit(98);
    }

    check_elf(header.e_ident);

    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abi(header.e_ident);
    print_type(header.e_type);
    print_entry(header.e_entry);

    close(fd);
}

void check_elf(unsigned char *e_ident) {
    if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }
}

void print_magic(unsigned char *e_ident) {
    printf(" Magic: ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

void print_class(unsigned char *e_ident) {
    printf(" Class: ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
            break;
    }
}

void print_data(unsigned char *e_ident) {
    printf(" Data: ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
            break;
    }
}

void print_version(unsigned char *e_ident) {
    printf(" Version: %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION]) {
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}


