#include "main.h"

/**
*_memset - fills memory with a constant byte
*@s: pointer of memory area
*@b: constant byte.
*@n: n bytes of the memory
*Return: returns new value of target
*/

char *_memset(char *s, char b, unsigned int n)
{
	while (n)
	{
		s[n - 1] = b;
		n--;
	}
	return (s);
}
