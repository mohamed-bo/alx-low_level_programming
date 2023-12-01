
#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash
 * @size: size
 * Return: pointer to hash
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->stail = NULL;
	ht->shead = NULL;
	return (ht);
}

/**
 * shash_table_set - set add elemt
 * @ht: hash
 * @key: key
 * @value: value
 * Return: 1 if succcess
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	char *strr;
	shash_node_t *newNode, *iter;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	strr = strdup(value);
	if (strr == NULL)
		return (0);
	iter = ht->shead;
	while (iter)
	{
		if (strcmp(iter->key, key) == 0)
		{
			free(iter->value);
			iter->value = strr;
			return (1);
		}
		iter = iter->snext;
	}
	newNode = malloc(sizeof(shash_node_t));
	if (newNode == NULL)
	{
		free(strr);
		return (0);
	}
	newNode->key = strdup(key);
	if (newNode->key == NULL)
	{
		free(strr);
		free(newNode);
		return (0);
	}
	newNode->value = strr;
	newNode->next = ht->array[idx];
	ht->array[idx] = newNode;
	if (ht->shead == NULL)
	{
		newNode->sprev = NULL;
		newNode->snext = NULL;
		ht->shead = newNode;
		ht->stail = newNode;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		newNode->sprev = NULL;
		newNode->snext = ht->shead;
		ht->shead->sprev = newNode;
		ht->shead = newNode;
	}
	else
	{
		iter = ht->shead;
		while (iter->snext != NULL && strcmp(iter->snext->key, key) < 0)
			iter = iter->snext;
		newNode->sprev = iter;
		newNode->snext = iter->snext;
		if (iter->snext == NULL)
			ht->stail = newNode;
		else
			iter->snext->sprev = newNode;
		iter->snext = newNode;
	}
	return (1);
}

/**
 * shash_table_get - get value
 * @ht: hash
 * @key: key
 * Return: value of key
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *iter;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	iter = ht->shead;
	while (iter != NULL && strcmp(iter->key, key) != 0)
		iter = iter->snext;
	return ((iter == NULL) ? NULL : iter->value);
}

/**
 * shash_table_print - Prints hash table
 * @ht: hash
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *itr;

	if (ht == NULL)
		return;

	itr = ht->shead;
	printf("{");
	while (itr != NULL)
	{
		printf("'%s': '%s'", itr->key, itr->value);
		itr = itr->snext;
		if (itr != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints hash reverse
 * @ht: hash
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *itr;

	if (ht == NULL)
		return;

	itr = ht->stail;
	printf("{");
	while (itr != NULL)
	{
		printf("'%s': '%s'", itr->key, itr->value);
		itr = itr->sprev;
		if (itr != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes hash
 * @ht: hash
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *iter;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node)
	{
		iter = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = iter;
	}
	free(head->array);
	free(head);
}
