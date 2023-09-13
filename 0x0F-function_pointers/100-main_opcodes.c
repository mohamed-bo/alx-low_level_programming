#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, n;

	/* check for correct number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* get number of bytes to print */
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* print opcodes */
	for (i = 0; i < n; i++)
	{
		printf("%.2x", ((unsigned char *)main)[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
