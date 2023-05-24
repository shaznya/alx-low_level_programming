#include <stdio.h>
#include "function_pointers.h"
/**
  *array_iterator - function that executes a function
  *@array: pointer to array
  *@size: size of array
  *@action: pointer function
  *Return: void
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	while (size--)
	{
		(*action)(*array++);
	}
}
