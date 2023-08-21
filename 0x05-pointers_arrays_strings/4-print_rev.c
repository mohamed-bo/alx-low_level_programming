#include "main.h"

/**
* print_rev - prints a string, in reverse
* @s: string to print
*/

void print_rev(char *s)
{

int i = 0;
int size = _strlen(s);

for (i = size - 1; i >= 0; i--)
_putchar(s[i]);

_putchar('\n');
}

int _strlen(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
}

return (i);
}
