#include "lists.h"

/**
 * tortoiseAndHaret - Tortoise and Hare Algorithm find loop
 * @head: head of list
 * Return: the real len of there is loop, else 0
 */

size_t tortoiseAndHaret(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t len = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	tortoise = head;
	hare = head;
	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			break;
	}
	if (tortoise == hare)
	{
		tortoise = head;
		while (tortoise != hare)
		{
			len++;
			tortoise = tortoise->next;
			hare = hare->next;
		}
		hare = hare->next;
		while (hare != tortoise)
		{
			len++;
			hare = hare->next;
		}
		return (len);
	}
	return (0);
}

/**
 * free_listint_safe - Free (safe version) a listint_t
 * @h: head of list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t len, i;

	len = tortoiseAndHaret(*h);
	if (!len)
	{
		for (i = 0; *h; i++)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
		}
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
		}
	}
	*h = NULL;
	h = NULL;
	return (i);
}
