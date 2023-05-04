#include "main.h"
/**
  *_strncpy -  copies a string
  *@dest: copy to
  *@src: copy from
  *@n: input
  *Return: char
  */
char *_strncpy(char *dest, char *src, int n)
{
	int len;

	len = 0;
	while (len < n && src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	while (len < n)
	{
		dest[len] = '\0';
		len++;
	}

	return (dest);
}
