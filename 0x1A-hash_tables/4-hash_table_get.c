#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: hash
 * @key: key
 * Return: value associated the element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node = NULL;
	unsigned long int i = 0;

	if (ht == NULL || key == NULL)
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	node = ht->array[i];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
