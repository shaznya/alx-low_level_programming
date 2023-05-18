#include "main.h"
#include <stdlib.h>
/**
  *malloc_checked -  allocates memory
  *@b: size input
  *Return: pointer to the allocated mem
  */
void *malloc_checked(unsigned int b)
{
	int *ptr;

	ptr = (int *) malloc(b * sizeof(int));

	if (ptr == NULL)
	{
		exit(98);
	}
	if (ptr != NULL)
	{
		return (ptr);
	}
	return (0);
}
