#include "main.h"

/**
 *leet - encodes a string into 1337.
 *@s: string to encode
 *Return: encoded string
 */

char *leet(char *s)
{

	int letters[11] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	int numbers[11] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};

	int i, j;

	for (j = 0; s[j] != '\0'; j++)
	{
		for (i = 0; i<11; i++)
		{
			if (s[j] == letters[i])
				s[j] = numbers[i];
		}
	}

	return (s);
}
