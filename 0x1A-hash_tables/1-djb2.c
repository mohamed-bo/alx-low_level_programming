#include "hash_tables.h"

/**
* hash_djb2 - implementing the djb2 algorithm.
 * @str: string
 * Return: hash
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int cha;

	if (str == NULL)
		return (0);
	while ((cha = *str++))
		hash = ((hash << 5) + hash) + cha;
	return (hash);
}
