#include <stdio.h>
#include "main.h"
/**
  *print_binary - prints the binary representation of a number
  *@n: input number
  */
void print_binary(unsigned long int n)
{
	unsigned long int bit;
	int find_one = 1;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	bit = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (bit > 0)
	{
		if ((n & bit) != 0)
		{
			find_one = 0;
			_putchar('1');
		}
		else if (!find_one)
		{
			_putchar('0');
		}
		bit >>= 1;
	}
}
