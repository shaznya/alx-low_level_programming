#include "main.h"
/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int s = 0;
	int ptr = 0;

	while (*(src + s) != '\0')
	{
		s++;
	}
	for ( ; ptr < s ; ptr++)

	{
		dest[ptr] = src[ptr];
	}
	dest[s] = '\0';
	return (dest);
}
