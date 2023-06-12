#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_error(const char *message);
void display_elf_header(const Elf64_Ehdr *header);
/**
  *display_error - displays an error message
  *@message: error message to be displayed
  *Return: 0
  */
void display_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}
/**
  *display_elf_header - displays the information contained in the ELF header
  *@header: input argument
  *Return: 0
  */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("Class: ");

	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;

		case ELFCLASS64:
			printf("ELF64\n");
			break;

		default:
			printf("Unknown\n");
	}
	printf("Data: ");

	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;

		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("Entry point address: 0x%lx\n", header->e_entry);
}
/**
  *main - main entry
  *@argc: number of arguments passed
  *@argv: array of pointer to the arguments
  *Return: total no. of arguments
  */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t read_bytes;

	if (argc != 2)
	{
		display_error("Usage: elf_header elf_filename");
	}
	filename = argv[1];

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		display_error("Failed to open the file");
	}
	read_bytes = read(fd, &header, sizeof(header));
	if (read_bytes == -1)
	{
		display_error("Failed to read the ELF header");
	}
	if (read_bytes < (ssize_t)sizeof(header))
	{
		display_error("Incomplete ELF header");
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		display_error("Not an ELF file");
	}
	display_elf_header(&header);

	if (close(fd) == -1)
	{
		display_error("Failed to close the file");
	}
	return (0);
}
