#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: head of list.
 * @idx: index to add new element
 * @n: data of new node
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *iter;
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if (head == NULL || new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	iter = *head;

	for (i = 0; i < idx - 1 && iter; i++)
	{
		iter = iter->next;
	}
	if (iter == NULL)
	{
		free(new);
		return (NULL);
	}

	new->next = iter->next;
	iter->next = new;
	return (new);
}
