#include <stdio.h>
#include "main.h"
/**
  *main -  program that prints its name
  *@argc: number of arguments
  *@argv: array of arguments
  *Return: void
  */
int main(int argc  __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}
