#include "main.h"
#include <stdlib.h>
/**
  *str_concat - concatenates two strings
  *@s1: dest
  *@s2: src
  *Return: char
  */
char *str_concat(char *s1, char *s2)
{
	char *combo;
	int i, n;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";


	i = n = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[n] != '\0')
		n++;
	combo = malloc(sizeof(char) * (i + n + 1));

	if (combo == NULL)
		return (NULL);
	i = n = 0;
	while (s1[i] != '\0')
	{
		combo[i] = s1[i];
		i++;
	}

	while (s2[n] != '\0')
	{
		combo[i] = s2[n];
		i++, n++;
	}
	combo[i] = '\0';
	return (combo);
}
