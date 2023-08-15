#include "main.h"

/**
 * main - print _putchar followed by new line
 * Return: 0
 */

int main(void)
{
	int i;
	char c[] = "_putchar";

	for (i = 0; i < strlen(c); i++)
		{
		_putchar(c[i]);
		}
		_putchar('\n');
	return (0);
}
