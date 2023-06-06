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
	const listint_t *current = head;
	size_t count = 0;
	int loop_detected = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (current <= current->next)
		{
			loop_detected = 1;
			break;
		}
		current = current->next;
	}
	if (loop_detected)
	{
		printf("Error: Infinite loop detected\n");
		exit(98);
	}
	current = current->next;

	return (count);
}
