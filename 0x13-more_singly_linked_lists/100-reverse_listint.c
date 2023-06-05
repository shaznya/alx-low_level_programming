#include <stdio.h>
#include "lists.h"
/**
  *reverse_listint - reverses a listint_t linked list.
  *@head: ponter to pointer to head of listint_t list
  *Return: a pointer to the first node of the reversed list
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous;
	listint_t *current;
	listint_t *next;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (*head);

	previous = NULL;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
	return (*head);
}
