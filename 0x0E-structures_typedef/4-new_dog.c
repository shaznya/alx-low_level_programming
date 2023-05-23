#include <stdio.h>
#include "dog.h"
#include <stdlib.h>
/**
 *_strlen - returns the length of a string
 *@s: string to evaluate
 *Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/**
 *_strcpy - copies the string including '\0'
 *@dest: pointer to the buffer in which we copy the string
 *@src: string to be copied
 *Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int j, i;

	j = 0;

	while (src[j] != '\0')
	{
		j++;
	}
	for (i = 0; i < j; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
  *new_dog - creates a new dog
  *@name: name of dog structure type
  *@age: age of new dog
  *@owner: new owner
  *Return: pointer to the new dog/NULL if it fails
  */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *pup;

	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);
	pup = malloc(sizeof(dog_t));
	if (pup == NULL)
		return (NULL);
	pup->name = malloc(sizeof(char) * (len1 + 1));

	if (pup->name == NULL)
	{
		free(pup);
		return (NULL);
	}
	pup->owner = malloc(sizeof(char) * (len2 + 1));
	if (pup->owner == NULL)
	{
		free(pup);
		free(pup->name);
		return (NULL);
	}
	_strcpy(pup->name, name);
	_strcpy(pup->owner, owner);
	pup->age = age;
	return (pup);
}
