#include "3-calc.h"
#include <stdio.h>

/**
 * add - adds two integers
 * @a: integer
 * @b: integer
 * Return: sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtracts two integers
 * @a: integer
 * @b: integer
 * Return: sub of a and b
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two integers
 * @a: integer
 * @b: integer
 * Return: mul of a and b
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * mod - computes the remainder of the division of two integers
 * @a: integer
 * @b: integer
 * Return: remainder of the division of a by b
 */
int mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
