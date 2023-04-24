#include <stdio.h>
/**
  *main - Entry point
  *prints all possible different combinations of three digits
  *Return: Always 0
  */
int main(void)
{
	int n, m, o;
	for (n = '0'; n < 9; n++)
	{
		for (m = n + 1; m <= 9; m++)
		{
			for (o = m + 1; o <= 9; o++)
			{
				if ((m !=n) != o)
				{
					putchar(n);
					putchar(m);
					putchar(o);
					if (n == 7 || m == 8)
						continue;
					putchar(',');
					putchar(' ');
				}}}}
	putchar('\n');
	return(0);
}
