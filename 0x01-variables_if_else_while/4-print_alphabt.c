#include <stdio.h>
/**
  *mai - Entry point
  *prints the alphabet in lowercase
  *Return: Always 0(success)
  */
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		if (n == 101 || n == 133)
		{
			n++;
			continue;
		}
		putchar('\n');
		return (0);
	}
}
