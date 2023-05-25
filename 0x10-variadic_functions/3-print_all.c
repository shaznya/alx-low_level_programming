#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
  *print_all - prints anything
  *@format: argument passed
  *Return: void
  */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *any = "";

	va_list anything;

	va_start(anything, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", any, va_arg(anything, int));
					break;
				case 'i':
					printf("%s%d", any, va_arg(anything, int));
					break;
				case 'f':
					printf("%s%f", any, va_arg(anything, double));
					break;
				case 's':
					str = va_arg(anything, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", any, str);
					break;
				default:
					i++;
					continue;
			}
			any = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(anything);
}
