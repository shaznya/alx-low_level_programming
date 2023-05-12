#include "main.h"
/**
  *puts_half -  prints half of a string
  *@str: half string
  *Return: 0
  */
void puts_half(char *str)
{
	int a, n, Str;

	Str = 0;

	for (a = 0; str[a] != '\0'; a++)
		Str++;

	n = (Str / 2);

	if ((Str % 2) == 1)
		n = ((Str + 1) / 2);

	for (a = n; str[a] != '\0'; a++)
		_putchar(str[a]);
	_putchar('\n');
}
