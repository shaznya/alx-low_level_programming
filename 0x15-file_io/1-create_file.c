#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
/**
  *create_file - creates a file.
  *@filename: name of the file to create
  *@text_content: a NULL terminated string to write to the file
  *Return: 1 on success, -1 on failure
  */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
        return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t len = strlen(text_content);
		ssize_t bytesWritten = write(fd, text_content, len);

		if (bytesWritten == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
