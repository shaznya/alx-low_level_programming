#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *sum_listint - returns the sum of all the data (n) of a listint_t linked list
  *@head: pointer to head of listint_t list
  *Return: sum of all the data (n) of a listint_t linked list.
  */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum = sum + current->n;
		current = current->next;
	}
	return (sum);
}
