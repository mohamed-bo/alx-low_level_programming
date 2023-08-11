#include <stdio.h>

/**
 *main - prints all the numbers of base 16 in lowercase
 *Return: Always 0 (Success)
 */

int main(void)
{
	int n = '0';
	int a_f = 'a';

	while (n <= '9')
	{
		putchar(n);
		n++;
	}

	while (a_f <= 'f')
	{
		putchar(a_f);
		a_f++;
	}

	putchar('\n');

	return (0);
}
