#include "lists.h"
#include <stdio.h>

/**
 * tortoiseAndHare - Tortoise and Hare Algorithm find loop
 * @head: head of list
 * Return: the real len of there is loop, else 0
 */

size_t tortoiseAndHare(const listint_t *head)
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
 * print_listint_safe - Print (safe version) list.
 * @head: head of list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t len, i;

	len = tortoiseAndHare(head);

	if (len)
	{
		for (i = 0; i < len; i++, head = head->next)
			printf("[%p] %d\n", (void *) head, head->n);
		printf("-> [%p] %d\n", (void *) head, head->n);
	}
	else
	{
		for (; head; len++, head = head->next)
			printf("[%p] %d\n", (void *) head, head->n);
	}
	return (len);
}
