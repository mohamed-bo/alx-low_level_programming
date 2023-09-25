#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of linked list.
 * @head: head of list.
 * @index: is the index of the node that should be deleted
 * Return: return 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *toDelete;
	unsigned int i;

	if (head == NULL || *head == NULL || index < 0)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	temp = *head;
	for (i = 0; i < index - 1 && temp; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
		return (-1);

	toDelete = temp->next;
	temp->next = toDelete->next;
	free(toDelete);
	return (1);
}
