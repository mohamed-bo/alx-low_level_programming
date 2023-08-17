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

	for (lines = 0; lines < size; lines++)
	{
		for (columns = 0; columns < (size - lines); columns++)
			_putchar(' ');

		for (diaz = 0; diaz < lines; diaz++)
			_putchar('#');

		_putchar('\n');
	}
}
