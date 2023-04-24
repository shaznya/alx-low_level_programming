#include <stdio.h>
/**
  *main - Entry point
  *Prints alphabet in lowercase
  *Return: Always 0
  */
int main(void)
{
	char low, e, q;

	e = 'e';
	q = 'q';

	for (low = 'a'; low <= 'z'; low++)
	{
		if (low != e && low != q)
			putchar(low);
	}
	putchar('\n');
	return (0);
}
