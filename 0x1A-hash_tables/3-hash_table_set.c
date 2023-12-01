
#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hashtble
 * @key: key
 * @value: value
 * Return: U1 if success
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newNode;
	char *str;
	unsigned long int i, index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	str = strdup(value);
	if (str == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = str;
			return (1);
		}
	}
	newNode = malloc(sizeof(hash_node_t));
	if (newNode == NULL)
	{
		free(str);
		return (0);
	}
	newNode->key = strdup(key);
	if (newNode->key == NULL)
	{
		free(str);
		free(newNode);
		return (0);
	}
	newNode->value = str;
	newNode->next = ht->array[index];
	ht->array[index] = newNode;
	return (1);
}
