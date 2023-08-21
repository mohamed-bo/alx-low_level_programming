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
	c = rand() % 128;
	while (sumOfC <= 2645 && c != 0)
	{
		sumOfC += c;
		putchar(c);
		c = rand() % 128;
	}
	putchar(2772 - sumOfC);
	return (0);
}
