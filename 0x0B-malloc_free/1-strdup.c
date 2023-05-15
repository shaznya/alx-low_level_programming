#include "main.h"
#include <stdlib.h>

/**
  *_strdup -  returns a pointer to a newly allocated space in memory
  *@str: pointer to original memory
  *Return: char
  */
char *_strdup(char *str)
{
	int i = 0;
	int n = 0;

	char *duplicate;

	if (str == NULL)
		return(NULL);
	duplicate = (char *) malloc(n + 1 * sizeof(char));

	if (duplicate == NULL)
		return (NULL);
	for (; i < n; i++)
	{
		duplicate[i] = str[i];
		n--;
	}
	return (duplicate);
}
