#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @h: head of list.
 * @index: is the index of the node, starting at 0
 * Return: the nth node of a listint_t linked list.
 * if the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int iter;

	for (iter = 0; iter < index && head; iter++)
		head = head->next;

	return (head);
}
