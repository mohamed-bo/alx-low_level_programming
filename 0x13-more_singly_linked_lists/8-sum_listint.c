#include "lists.h"

/**
 * sum_listint -the sum of all the data (n) of a listint_t linked list.
 * @head: head of list.
 * Return: the sum of all the data (n) of a listint_t linked list.
 */

int sum_listint(listint_t *head)
{
	int sum;

	for (sum = 0; head; head = head->next)
		sum += head->n;

	return (sum);
}
