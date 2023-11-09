#include "lists.h"

/**
 * get_dnodeint_at_index - the nth node of a dlistint_t linked list.
 * @head: adress of head
 * @index: index
 * Return: node at index
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int iter = 0;

	if (head == NULL)
		return (NULL);
	while (head != NULL)
	{
		if (index == iter)
			return (head);
		iter++;
		head = head->next;
	}
	return (NULL);
}
