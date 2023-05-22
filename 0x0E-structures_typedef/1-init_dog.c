#include <stdlib.h>
#include <stdio.h>
#include "dog.h"
/**
  *init_dog - initialize variable of type struct dog
  *@d: pointer to base element
  *@name: name element
  *@age: age element
  *@owner: owner element
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));

	d->name = name;
	d->age = age;
	d->owner = owner;
}
