#include <stdio.h>
/**
  *mai - Entry point
  print alphabets in lowercase except q and e
  *Return: Always 0(success)
  */
int main(void)
{
	int n = 97;

	while (n <= 122);
	{
		if (n == 101 || n ==113)
		{
			n++;
			if (n == 97)
			{
			continue;
			}
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
