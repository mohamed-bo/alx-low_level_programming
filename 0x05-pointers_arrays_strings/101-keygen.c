#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords
 * Return: 0 if success
 */

int main(void)
{
	char c;
	int sumOfC;

	srand(time(0));
	while (sumOfC <= 2645)
	{
		c = rand() % 128;
		sumOfC += c;
		putchar(c);
	}
	putchar(2772 - sumOfC);
	return (0);
}
