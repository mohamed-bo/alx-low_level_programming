#include "lists.h"

/**
 * pop_listint - deletes and returns the head node’s data (n).
 * @h: head of list.
 * Return: the head node’s data (n).if the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
	listint_t *oldHead;
	int n;

	if (*head == NULL)
		return (0);
	oldHead = *head;
	n = oldHead->n;
	*head = (*head)->next;
	free(oldHead);
	return (n);
}
