#include <stdlib.h>
#include "lists.h"
/**
 *free_list - frees a list_t list
 *@head: pointer to the header node
 *Return: 0
 */
void free_list(list_t *head)
{
	list_t *current = head;
	list_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}
}
