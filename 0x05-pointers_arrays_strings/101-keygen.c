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
	int checksum;

	srand(time(0));
	c = rand() % 96 + 32;
	while (checksum <= 2645)
	{
		checksum += c;
		putchar(c);
		c = rand() % 96 + 32;
	}
	putchar(2772 - checksum);
	return (0);
}
