#include "main.h"
/**
  *is_prime_number -  input integer is a prime number
  *@n: input int
  *Return: int
  */
int is_prime_number(int n)
{
	if (n / 1 == n && n / n == 1)
	{
		return (1);
	}
	else
		is_prime_number(n + 1);
			return (0);
}
