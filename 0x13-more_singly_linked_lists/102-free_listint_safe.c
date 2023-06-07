#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
/**
  *free_listint_safe - frees a listint_t list.
  *@h: pointer to ponter to head of listint_t list
  *Return: size of the list that was free’d
  */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int difference;
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		difference = *h - (*h)->next;

		if (difference > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}
	*h = NULL;

	return (length);
}
