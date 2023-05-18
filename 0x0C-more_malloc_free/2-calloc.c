#include "main.h"
#include <stdlib.h>
/**
  *_calloc - allocates memory for an array
  *@nmemb: no of elements
  *@size: size of elements
  *Return: void
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int *array;

	array = (int *) malloc(size * sizeof(int));

	if (array[nmemb] == 0)
	{
		return (array);
	}
	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	if (array == NULL)
	{
		return (NULL);
	}
	return (0);
}

