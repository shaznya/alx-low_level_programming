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
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
