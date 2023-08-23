#include "main.h"
/**
*print_buffer -  function that prints a buffer
*@b: the buffer
*@size: size of the buffer
*/
void print_buffer(char *b, int size)
{
	int i, j, k;
	int c;

	i = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}

	while (i < size)
	{
		j = size - i < 10 ? size - i : 10;
		printf("%08x: ", i);
		for (k = 0; k < 10; k++)
		{
			if (k < j)
				printf("%02x", *(b + i + k));
			else
				printf("  ");
			if (k % 2)
				printf(" ");
		}
		for (k = 0; k < j; k++)
		{
			c = *(b + i + k);
			if (c < 32 || c > 128)
				c = '.';
			printf("%c", c);
		}
		printf("\n");
		i = i + 10;
	}
}
