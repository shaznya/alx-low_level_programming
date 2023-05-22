#include <stdio.h>
#include "dog.h"
#include <stdlib.h>
/**
  *print_dog -  prints a struct dog
  *@d: variable pointer
  */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		d->name = "(nil)";
	if (d->owner == NULL)
		d->owner = "(nil)";


	printf("%s\n", d->name);
	printf("%.1f\n", d->age);
	printf("%s\n", d->owner);
}
