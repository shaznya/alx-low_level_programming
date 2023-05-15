#include "main.h"
#include <stdlib.h>
/**
  *create_array - creates an array of chars
  *@c: variable char
  *@size: araay size
  *Return: char
  */
char *create_array(unsigned int size, char c)
{
	int i = 0;

	*c = (char *) malloc(size * sizeof(char));

		for (i = 0; i < size; i++)
		{
			if(c[i] == c);
			{
			return (*c);
			}
			else
			{
			return (NULL);
			}
}
