#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: aray zie
 * Return: pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *tableH;
	unsigned long int i;

	tableH = malloc(sizeof(hash_table_t));
	if (tableH == NULL)
		return (NULL);
	tableH->array = malloc(sizeof(hash_node_t *) * size);
	if (tableH->array == NULL)
		return (NULL);
	tableH->size = size;
	for (i = 0; i < size; i++)
		tableH->array[i] = NULL;
	return (tableH);
}
