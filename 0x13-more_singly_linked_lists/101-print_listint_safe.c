#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
  *print_listint_safe -  prints a listint_t linked list.
  *@head: pointer to head of listint_t list
  *Return: the number of nodes in the list
  */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp = NULL;
	const listint_t *loopnode = NULL;
	size_t count = 0;
	size_t newcount;

	temp = head;
	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;
		temp = temp->next;
		loopnode = head;
		newcount = 0;

		while (newcount < count)
		{
			if (temp == loopnode)
			{
				printf("-> [%p] %d\n", (void *)temp, temp->n);
				return (count);
			}
			loopnode = loopnode->next;
			newcount++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
