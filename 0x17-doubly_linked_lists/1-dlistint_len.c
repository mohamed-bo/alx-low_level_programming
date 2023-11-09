#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len -  the number of elements in a linked dlistint_t list.
 * @h: adress de header
 * Return: the number of elements in a linked dlistint_t list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t number = 0;

	while (h)
	{
		number++;
		h = h->next;
	}
	return (number);
}
