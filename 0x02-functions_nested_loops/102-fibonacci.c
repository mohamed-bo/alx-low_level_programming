#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	int i = 1;
	long f = 1;
	long s = 1;

	while (i <= 50)
	{
		printf("%d, ", i);
		f = s;
		s = i;
		i = s + f;
	}
	printf("\n");

	return (0);
}
