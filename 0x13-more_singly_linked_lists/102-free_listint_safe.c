#include <stdlib.h>
#include "lists.h"
/**
  *free_listint_safe - frees a listint_t list.
  *@h: pointer to pointer to head of listint_t
  *Return: the size of the list that was free’d
  */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *next;
	size_t count = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;

		if (current >= next)
		{
			*h = NULL;
			break;
		}
		current = next;
	}
	return (count);
}
