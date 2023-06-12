#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/**
  *read_textfile -  reads a text file and prints it
  *@filename: file to be printed
  *@letters: number of letters it should read and print
  *Return: actual number of letters it could read and print
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytesRead;
	ssize_t bytesWritten;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buffer = (char *)malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytesRead = read(fd, buffer, letters);
	if (bytesRead <= 0)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten != bytesRead)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	free(buffer);

	return (bytesRead);
}
