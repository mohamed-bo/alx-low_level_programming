#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	int counter = 0;
	int i = 1;
	long f = 1;
	long s = 1;

	while (counter < 50)
	{
		printf("%li, ", i);
		f = s;
		s = i;
		i = s + f;
		counter++;
	}
	printf("\n");

	return (0);
}
