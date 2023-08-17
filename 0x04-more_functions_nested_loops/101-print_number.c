#include "main.h"

/**
 * print_number - print an integer using putchar
 * @n: number to be printed
 */

void print_number(int n)
{
	unsigned int tens, digit, number_positive = n;
	double biggerTens = 1;

	if (n == 0)
		_putchar('0');
	else
	{
		if (n < 0)
		{
			number_positive = n * -1;
			_putchar('-');
		}

		while (biggerTens <= number_positive)
		{
			biggerTens *= 10;
		}

		tens = biggerTens / 10;

		while (tens >= 1)
		{
			digit = number_positive / tens;
			_putchar(digit + '0');
			number_positive = (number_positive - (tens * digit));
			tens /= 10;
		}
	}
}
