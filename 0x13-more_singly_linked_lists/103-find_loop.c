#include "lists.h"
#include <stdio.h>
#include <stddef.h>
/**
  *find_listint_loop - finds the loop in a linked list
  *@head: pointer to head of listint_t list
  *Return: address of the node or NULL if there is no loop
  */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *once = head;
	listint_t *twice = head;

	while (twice != NULL && twice->next != NULL)
	{
		once = once->next;
		twice = twice->next->next;

		if (once == twice)
		{
			once = head;
			while (once != twice)
			{
				once = once->next;
				twice = twice->next;
			}
			return (once);
		}
	}
	return (NULL);
}
