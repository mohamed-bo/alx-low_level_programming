#include "main.h"

/**
 * factorial - returns the factorial of a given number.
 * @n: number
 * Return: the factorial of a given number
 * if n negative return -1
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
