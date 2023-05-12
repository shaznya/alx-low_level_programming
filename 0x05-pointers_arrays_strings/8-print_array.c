#include "main.h"
/**
  *print_array -  prints n elements of an array of integers
  *@a: pointer
  *@n: value
  *Return: 0
  */
void print_array(int *a, int n)
{
	int array;

	for (array = 0; array < (n - 1); array++)
	{
		printf("%d, ", a[array]);
	}
		if (array == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}
