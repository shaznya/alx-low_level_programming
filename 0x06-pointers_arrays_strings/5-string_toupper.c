#include "main.h"
/**
  *string_toupper - lower to uppercase
  *Return: char
  */
char *string_toupper(char *)
{
	int i;

	i = 0;
	while (*[i] != '\0')
	{
		if (*[i] >= 'a' && *[i] <= 'z')
			*[i] = *[i] - 32;
		i++;
	}
	return (*);
}
