#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i = 0;
	char *sep = "";

	if (!ht || !ht->array)
		return;
	putchar('{');
	while (i < ht->size)
	{
		node = ((ht->array)[i]);
		while (node)
		{
			printf("%s'%s': '%s'", sep, node->key, node->value);
			sep = ", ";
			node = node->next;
		}
		i++;
	}
	puts("}");
}
