#include "lists.h"

/**
 * _strlen - length of a string
 * @s: string
 * Return: the length of string
 */
int _strlen(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
}

return (i);
}

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: adress of the head node
 * @str: string of new node
 * Return: address of the new head
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;
	return (new);
}
