#include "lists.h"

/**
 * add_dnodeint_end - that adds a new node at the end of a dlistint_t list.
 * @head: adress of head
 * @n: value
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode = NULL, *iter = *head;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = newNode;
		return (*head);
	}
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	newNode->prev = iter;
	iter->next = newNode;
	return (newNode);
}
