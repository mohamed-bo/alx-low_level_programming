#include "main.h"

/**
 * print_triangle - print traingle in specefic size
 * @size: size of triangle
 */

void print_triangle(int size)
{
	int lines;
	int columns;
	int diaz;

	if (size <= 0)
		_putchar('\n');

	for (lines = 1; lines <= size; lines++)
	{
		for (columns = 1; columns <= (size - lines); columns++)
			_putchar(' ');

		for (diaz = 1; diaz <= lines; diaz++)
			_putchar('#');

		_putchar('\n');
	}
}
