#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
  *sum_them_all -  returns the sum of all its parameters
  *@n: number of arguments as the first parameter
  *Return:  returns the sum of all its parameters
  */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i = 0;
	int result = 0;

	va_list args;

	va_start(args, n);

	if (n == 0)
	{
		return (0);
	}
	for (i = 0; i < n; i++)
	{
		int arg = va_arg(args, const unsigned int);

		result =  result + arg;
	}
	va_end(args);
	return (result);
}
