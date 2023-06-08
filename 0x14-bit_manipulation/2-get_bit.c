#include <stdio.h>
#include "main.h"
/**
  *get_bit -  returns the value of a bit at a given index
  *@n: input number
  *@index: index of each bit value
  *Return: the value of the bit at index index or -1
  */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	if ((n & bit) != 0)
		return (1);
	return (0);
}
