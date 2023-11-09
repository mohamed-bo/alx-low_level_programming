#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index.
 * @head: adress of head
 * @index: index
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i;

	if (!*head || !head)
		return (-1);
	temp = *head;
	for (i = 0; temp && i < index; i++)
		temp = temp->next;
	if (!temp)
		return (-1);
	if (temp->prev)
		temp->prev->next = temp->next;
	else
		*head = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	return (1);
}

