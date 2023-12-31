#include "lists.h"
#include <string.h>

/**
 * _strlen - length of a string
 * @s: string
 * Return: the length of string
 */
int _strlen(const char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
}

return (i);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: adress of the head node
 * @str: string of new node
 * Return: address of the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *node;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = new;
	}
	return (new);
}

