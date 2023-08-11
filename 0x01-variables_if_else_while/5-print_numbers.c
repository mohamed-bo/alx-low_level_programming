#include <stdio.h>

/**
 *main - print all single digit.
 *Return: Always 0 (Success)
 */

int main(void)
{
	int n = 0;

	while (n < 10)
	{
		printf("%d", n);
		n++;
	}
	putchar('\n');

	return (0);
}
