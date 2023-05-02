#include "main.h"
/**
  *puts2 -  prints every other character of a string
  *@str: print character
  *Return: 0
  */
void puts2(char *str)
{
	int Str = 0;
	int t = 0;
	char *y = str;
	int o;

	while (*y != '\0')
	{
		y++;
		Str++;
	}
	t = Str - 1;
	for (o = 0 ; o <= t ; o++)
	{
		if (o % 2 == 0)
	{
		_putchar(str[o]);
	}
	}
	_putchar('\n');
}
