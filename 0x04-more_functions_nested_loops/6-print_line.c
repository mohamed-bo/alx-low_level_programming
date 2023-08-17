#include "main.h"

/**
 * print_line - print "_" n times
 * @n: number of "_" should be printed
 */

void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar('_');

	_putchar('\n');
}
