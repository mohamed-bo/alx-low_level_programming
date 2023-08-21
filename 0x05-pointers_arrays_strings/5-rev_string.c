#include "main.h"

/**
*rev_string - reverses a string.
*@s: string to reverse
*/

void rev_string(char *s)
{
	int i = 0, size;
	size = _strlen(s) - 1;

	while (size > i)
	{
		swap_char(s + size, s + i);
		i++;
		size--;
	}
}
