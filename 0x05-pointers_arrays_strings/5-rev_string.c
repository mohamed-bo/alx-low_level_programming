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

/**
 *_strlen -  function that returns the length of a string.
 * @s: string value
 *Return: returns the length of a string.
 */
 
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}

	return (i);
}

/**
*swap_char - swap two characters variable
*@a: first character
*@b: second character
*/

void swap_char(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
