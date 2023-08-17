#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 * Return: 0 on success
 */

int main(void)
{
	long number = 612852475143;
	long divisor = 2;

	while (divisor < number)
	{
		if (number % divisor == 0)
		{
			number = number / divisor;
			divisor = 2;
		}
		else
			divisor++;
	}
	printf("%ld\n", number);
	return (0);
}
