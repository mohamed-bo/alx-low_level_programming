#include "main.h"

/**
 * print_last_digit - prints the last digit of a number.
 * @n: integer value
 * Return: last digit of a number
 */

int print_last_digit(int n)
{
	if (n < 0)
	{
		n = -(n % 10);
	}
	else
	{
		n = (n % 10);
	}
	_putchar('0' + n);

	return (n);
}
