#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *pop_listint - deletes the head node of a listint_t linked list
  *@head: pointer to pointer to head of listint_t list
  *Return:  the head node’s data (n)
  */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	data = (*head)->n;

	temp = *head;
	data = temp->n;
	*head = (*head)->next;

	free(temp);

	return (data);
}
