#include "main.h"

/**
 * print_number - print an integer using putchar
 * @n: number to be printed
 */

void print_number(int n)
{
	int tens, digit;
	unsigned int positive = n;
	unsigned int biggerTens = 1;

	if (n == 0)
		_putchar('0');
	else
	{
		if (n < 0)
		{
			positive = n * -1;
			_putchar('-');
		}

		while (biggerTens <= positive)
			biggerTens = biggerTens * 10;
		tens = biggerTens / 10;

		while (tens >= 1)
		{
			digit = positive / tens;
			_putchar(digit + '0');
			positive = (positive - (tens * digit));
			tens = tens / 10;
		}
	}
}
