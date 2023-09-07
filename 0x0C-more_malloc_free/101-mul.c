#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * isNumber - checks if a string contains only numbers
 * @s: string
 * Return: 1 if number, 0 if not
 */

int isNumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

/**
 * main - multiplies two positive numbers.
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	int i, j, lenFistNumber, lenSecondNumber, multiplication, sum;
	int *result;

	if (ac != 3 || !isNumber(av[1]) || !isNumber(av[2]))
	{
		printf("Error\n");
		exit(98);
	}
	lenFistNumber = strlen(av[1]);
	lenSecondNumber = strlen(av[2]);
	result = calloc(lenFistNumber + lenSecondNumber, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = lenFistNumber - 1; i >= 0; i--)
	{
		for (j = lenSecondNumber - 1; j >= 0; j--)
		{
			multiplication = (av[1][i] - '0') * (av[2][j] - '0');
			sum = result[i + j + 1] + multiplication;
			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
	for (i = 0; i < lenFistNumber + lenSecondNumber && result[i] == 0; i++)
		;
	if (i == lenFistNumber + lenSecondNumber)
		printf("0");
	for (; i < lenFistNumber + lenSecondNumber; i++)
		printf("%d", result[i]);
	printf("\n");
	free(result);
	return (0);
}
