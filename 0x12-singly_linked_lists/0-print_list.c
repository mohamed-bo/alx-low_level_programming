#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list.
 * @h: adress of the head node
 * Return: legnth of list
 */

size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		if (h->str)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");
		h = h->next;
		i++;
	}
	return (i);
}
