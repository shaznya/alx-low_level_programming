#include "main.h"
#include <stdlib.h>

/**
  *_strdup -  returns a pointer to a newly allocated space in memory
  *@str: pointer to original memory
  *Return: char
  */
char *_strdup(char *str)
{
	char *duplicate;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	duplicate = malloc(sizeof(char) * (i + 1));

	if (duplicate == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		duplicate[r] = str[r];

	return (duplicate);
}
