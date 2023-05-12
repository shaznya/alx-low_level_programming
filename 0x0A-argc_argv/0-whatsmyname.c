#include <stdio.h>
#include "main.h"
/**
  *main -  program that prints its name
  *@argc: number of arguments
  *@agrv: array of arguments
  *Return: void
  */
int main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i > argc; i++)
	{
	printf("%s\n", argv[0]);
	}
	return (0);
}
