#include "main.h"
/**
*print_buffer -  function that prints a buffer
*@b: the buffer
*@size: size of the buffer
*/
void print_buffer(char *b, int size)
{
	int i = 0, j;

	if (size <= 0)
	{
		putchar('\n');
		return;
	}

	while (i < size)
	{
		if (i % 10 == 0)
			printf("%08x: ", i);
		for (j = i; j < i + 10; j += 2)
		{
			if ((j < size) && ((j + 1) < size))
				printf("%02x%02x ", b[j], b[j + 1]);
			else
			{
				j++;
				while (j <= i + 11)
				{
					printf("  ");
					j++;
				}
			}
		}
		for (j = i; j < i + 10 && j < size; j++)
		{
			if (b[j] >= 32 && b[j] <= 126)
				putchar(b[j]);
			else
				putchar('.');
		}
		putchar('\n');
		i = i + 10;
	}
}
