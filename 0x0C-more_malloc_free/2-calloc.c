#include "main.h"
#include <stdlib.h>
/**
 *_memset - fills memory with a constant byte
 *@s: memory area to be filled
 *@b: char to copy
 *@n: number of times to copy b
 *Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
/**
  *_calloc - allocates memory for an array
  *@nmemb: no of elements
  *@size: size of elements
  *Return: void
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array;

	if (nmemb == 0 || size == 0)
		return (NULL);

	array = malloc(size * nmemb);

	if (array == NULL)
		return (NULL);

	_memset(array, 0, nmemb * size);
	return (array);
}
