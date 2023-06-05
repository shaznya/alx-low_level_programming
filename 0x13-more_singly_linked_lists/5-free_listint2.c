#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
/**
  *free_listint2 - frees a listint_t list.
  *@head: pointer to pointer to head of listint_t list
  */
void free_listint2(listint_t **head)
{
	listint_t *current;
	listint_t *next;

	if (head == NULL)
		return;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
