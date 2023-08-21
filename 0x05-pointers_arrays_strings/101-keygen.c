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
	int x;

	srand(time(0));
	while (x <= 5000)
	{
		c = rand() % 128;
		x += c;
		putchar(c);
	}
	putchar(5127 - x);
	return (0);
}
