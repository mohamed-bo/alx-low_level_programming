#include <stdio.h>
#include <stdlib.h>

/**
* main - prints the program name
*@argc: The number of command line arguments
*@argv: array containing the program cmd line arguments
*Return: 0 on success
*1 on failure
*/

int main(int argc, char *argv[])
{
	int agrument, i, sum = 0;

	for (agrument = 1; agrument < argc; agrument++)
	{
		for (i = 0; argv[agrument][i] != '\0'; i++)
		{
			if (argv[agrument][i] < '0' || argv[agrument][i] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[agrument]);
	}

	printf("%d\n", sum);

	return (0);
}
