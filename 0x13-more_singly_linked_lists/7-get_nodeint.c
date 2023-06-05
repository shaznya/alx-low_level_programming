#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *get_nodeint_at_index -  returns the nth node of a listint_t linked list.
  *@head: pointer to head of lisyint_t list
  *@index: position of the nodes
  *Return:  nth node of a listint_t linked list
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}
	return (NULL);
}
