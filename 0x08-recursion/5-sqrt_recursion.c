#include "main.h"

/**
 * sqrt - the natural square root of a number
 * @n: number
 * @x: test this x
 * Return: natural square x
 * -1 if x not natural
 */

int sqrt(int n, int x)
{
	if (x * x > n)
		return (-1);

	if (x * x == n)
		return (x);

	return (sqrt(n, x + 1));
}

/**
 * _sqrt_recursion - the natural square root of a number
 * @n: number
 * Return: natural square x
 * -1 if x not natural
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt(n, 0));
}
