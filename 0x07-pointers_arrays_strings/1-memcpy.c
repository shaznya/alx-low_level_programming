#include "main.h"
/**
  *_memcpy - copies memory area
  *@dest: destination
  *@src: source
  *@n: integer
  *Return: char
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
