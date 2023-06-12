#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void display_usage_error(void);
void display_read_error(const char *filename);
void display_write_error(const char *filename);
void display_close_error(int fd);
void copy_file(const char *file_from, const char *file_to);
/**
  *display_usage_error - displays an error message
  */
void display_usage_error(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}
/**
  *display_read_error - displays an error message for file read failure
  *@filename: file to be read
  */
void display_read_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}
/**
  *display_write_error - displays an error message for file write failure
  *@filename: file to be written
  */
void display_write_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}
/**
  *display_close_error - an error message for file descriptor close failure
  *@fd: file descriptor
  */
void display_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
/**
  *copy_file - copies the content of one file to another file
  *@file_from: source file
  *@file_to: destination file
  */
void copy_file(const char *file_from, const char *file_to)
{
	int file_from_fd, file_to_fd;
	ssize_t read_bytes, write_bytes;
	char buffer[1024];

	file_from_fd = open(file_from, O_RDONLY);

	if (file_from_fd == -1)
		display_read_error(file_from);
	file_to_fd = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (file_to_fd == -1)
	{
		close(file_from_fd);
		display_write_error(file_to);
	}
	while ((read_bytes = read(file_from_fd, buffer, sizeof(buffer))) > 0)
	{
		write_bytes = write(file_to_fd, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			close(file_from_fd);
			close(file_to_fd);
			display_write_error(file_to);
		}
	}
	if (read_bytes == -1)
	{
		close(file_from_fd);
		close(file_to_fd);
		display_read_error(file_from);
	}
	if (close(file_from_fd) == -1)
		display_close_error(file_from_fd);
	if (close(file_to_fd) == -1)
		display_close_error(file_to_fd);
}
/**
  *main - entry point
  *@argc: no. of command line arguments
  *@argv: array of pointers to the command-line arguments
  *Return: no. of aruments passed
  */
int main(int argc, char *argv[])
{
	if (argc != 3)
		display_usage_error();

	copy_file(argv[1], argv[2]);

	return (0);
}
