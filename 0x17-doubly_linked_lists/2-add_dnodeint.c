#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: adress de header
 * @n: value
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;

	if (!head)
		return (NULL);
	newNode = malloc(sizeof(dlistint_t));
	if (!newNode)
		return (NULL);
	if (*head)
		(*head)->prev = newNode;
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
