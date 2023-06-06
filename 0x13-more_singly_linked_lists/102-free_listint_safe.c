#include <stdlib.h>
#include "lists.h"
/**
  *free_listint_safe - frees a listint_t list.
  *@h: pointer to pointer to head of listint_t
  *Return: the size of the list that was free’d
  */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tempt;
	int difference;

	if (h == NULL || *h == NULL)
		return (count);
	while (*h)
	{
		difference = *h - (*h)->next;
		if (difference > 0)
		{
			tempt = (*h)->next;
			free(*h);
			*h = tempt;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}
	*h = NULL;
	return (count);
}
