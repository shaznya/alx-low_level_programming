#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *free_listint -  frees a listint_t list.
  *@head: pointer to head of listint_t list
  */
void free_listint(listint_t *head)
{
	listint_t *current = head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
