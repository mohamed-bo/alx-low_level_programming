#include "lists.h"

/**
 * sum_dlistint - the sum of all the data (n) of a dlistint_t linked list.
 * @head: adress of head
 * Return: the sum of all the data (n) of a dlistint_t linked list.
 */

int sum_dlistint(dlistint_t *head)
{
	int s = 0;

	while (head != NULL)
	{
		s += head->n;
		head = head->next;
	}
	return (s);
}
