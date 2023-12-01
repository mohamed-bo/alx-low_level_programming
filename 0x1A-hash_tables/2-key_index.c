#include "hash_tables.h"

/**
 * key_index - Returns the index at which the key/value pair
 * @key: is the key
 * @size: size
 * Return: the index at which the key/value pair
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int keyI = hash_djb2(key) % size;

	return (keyI);
}
