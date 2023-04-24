#include <stdio.h>
/**
  *main - Entry point
  *Prints alphabet in lowercase
  *Return: Always 0
  */
int main(void)
{
	char n, m, o;

	m = 'e';
	o = 'q';

	for (n = 'a'; n <= 'z'; n++)
	{
		if (n != m || n != o)
			putchar(n);
	}
	putchar('\n');
	return (0);
}
