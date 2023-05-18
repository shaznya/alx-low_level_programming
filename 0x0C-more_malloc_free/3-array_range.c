#include "main.h"
#include <stdlib.h>
/**
  *array_range -  creates an array of integers
  *@min: first value
  *@max: last value
  *Return: int
  */
int *array_range(int min, int max)
{
	int *value;
	int i;
	int n;

	if (min > max)
		return (NULL);
	n = max - min + 1;

	value = malloc(sizeof(int) * n);

	if (value == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		value[i] = min++;

	return (value);
}
