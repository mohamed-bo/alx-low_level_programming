#include "main.h"

/**
 * get_endianness - that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int number = 1;
	char *ch = (char *)&number;

	return ((int)*ch);
}
