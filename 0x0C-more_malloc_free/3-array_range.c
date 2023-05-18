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
	int i = 0;
	int n = 0;

	for (i = 0; i < n; i++) 

	value = (int *) malloc(n * sizeof(int));
	if (min == 0 && max <= n) 
	{
	return (value);
	}
	if (min > max)
	{
		return (NULL);
	}
	if (value == NULL)
	{
		return (NULL);
	}
	return (0);
}
