#include "main.h"

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
*puts_half - prints half of a string
*@str: string to printed
*/

void puts_half(char *str)
{
	int size = _strlen(str);
	int i;

	if (size % 2 == 0)
		i = size / 2;

	else
		i = (size + 1) / 2;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
