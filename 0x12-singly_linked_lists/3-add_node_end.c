#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
  *add_node_end - adds a new node at the end of a list_t list
  *@head: pointer to pointer to next node
  *@str: pointer to string to be duplicated
  *Return: address of the new element, or NULL if it failed
  */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end_node;

	if (str == NULL)
		return (NULL);
	end_node = malloc(sizeof(list_t));
	if (end_node == NULL)
		return (NULL);
	end_node->str = strdup(str);
	if (end_node->str == NULL)
	{
		free(end_node);
		return (NULL);
	}
	end_node->len = strlen(end_node->str);
	end_node->next = NULL;
	if (*head == NULL)
	{
		*head = end_node;
	}
	else
	{
		list_t *current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = end_node;
	}
	return (end_node);
}
