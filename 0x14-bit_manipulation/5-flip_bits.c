#include "main.h"

/**
 * flip_bits - the number of bits need to flip to get from number to another.
 * @n: firstnumber
 * @m: second number
 * Return: the number of bits need to flip to get from number to another.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int i = 0;

	while (xor)
	{
		xor &= xor - 1;
		i++;
	}
	return (i);
}
