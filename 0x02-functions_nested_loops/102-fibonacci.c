#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	int counter = 0;
	long i = 1;
	long f = 1;
	long s = 1;

	while (counter < 49)
	{
		printf("%ld, ", i);
		f = s;
		s = i;
		i = s + f;
		counter++;
	}
	printf("%ld", i);
	printf("\n");

	return (0);
}
