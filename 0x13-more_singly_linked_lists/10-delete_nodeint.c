#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *delete_nodeint_at_index - deletes the node at index of a listint_t list.
  *@head: pointer to pointer to head of listint_t list
  *@index: index of listint_t node
  *Return: 1 if it succeeded, -1 if it failed
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	unsigned int count = 0;

	listint_t *current;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	current = *head;
	while (current != NULL && count < index - 1)
	{
		current = current->next;
		count++;
	}
	if (current == NULL || current->next == NULL)
		return (-1);
	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}
