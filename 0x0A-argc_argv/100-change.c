#include <stdio.h>
#include <stdlib.h>

/**
*main - prints the minimum number of coins to make change
*@argc: The number of command line arguments
*@argv: array containing the program cmd line arguments
*Return: 0 on success
*1 on failure
*/

int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	if (argv[1][0] == '-')
	{
		printf("0\n");
		return (0);
	}

	cents = atoi(argv[1]);

	coins += cents / 25;
	cents = cents % 25;
	coins += cents / 10;
	cents = cents % 10;
	coins += cents / 5;
	cents = cents % 5;
	coins += cents / 2;
	cents = cents % 2;
	coins += cents / 1;

	printf("%d\n", coins);
	return (0);
}
