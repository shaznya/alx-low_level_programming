#include <stdio.h>
#include "lists.h"
/**
  *reverse_listint - reverses a listint_t linked list.
  *@head: ponter to pointer to head of listint_t list
  *Return: a pointer to the first node of the reversed list
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *current = *head;


	while (current != NULL)
	{
		*head = current->next;
		current->next = previous;
		previous = current;
		current = *head;
	}
	*head = previous;
	return (previous);
}
