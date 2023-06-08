#include <stdio.h>
#include "main.h"
/**
  *flip_bits - returns the number of bits you would need to flip
  *@n: input number
  *@m: input number
  *Return: returns the number of bits you would need to flip
  */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_diff = n ^ m;
	unsigned int count = 0;

	while (bit_diff != 0)
	{
		count += bit_diff & 1;
		bit_diff >>= 1;
	}
	return (count);
}
