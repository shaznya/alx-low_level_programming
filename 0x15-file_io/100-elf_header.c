#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * display_error - Display an error message and exit
 * @message: The error message to display
 */
void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * display_magic - Display the magic numbers from the ELF header
 * @elf_header: The ELF header structure
 *
 * Description: Displays the magic numbers contained in the ELF header.
 */
void display_magic(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("  Magic:");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", elf_header->e_ident[i]);
	printf("\n");
}

/**
 * display_class - Display the class information from the ELF header
 * @elf_header: The ELF header structure
 *
 * Description: Displays the class information from the ELF header.
 */
void display_class(const Elf64_Ehdr *elf_header)
{
	printf("  Class:                             %s\n",
	       (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
}

/**
 * display_data - Display the data information from the ELF header
 * @elf_header: The ELF header structure
 *
 * Description: Displays the data information from the ELF header.
 */
void display_data(const Elf64_Ehdr *elf_header)
{
	printf("  Data:%35s%s\n", "", (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" :
			 "2's complement, big endian");
}
/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, 98 on error
 *
 * Description: The main function of the program.
 */
int main(int argc, char *argv[])
{
	const char *file_name;
	int fd;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file_name = argv[1];
	fd = open(file_name, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(98);
	}
	bytes_read = read(fd, &elf_header, sizeof(elf_header));

	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", file_name);
		exit(98);
	}

	printf("ELF Header:\n");

	display_magic(&elf_header);
	display_class(&elf_header);
	display_data(&elf_header);

	close(fd);

	return (0);
}
