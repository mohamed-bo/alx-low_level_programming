#include "main.h"

/**
* is_prime - returns 1 if the integer is a prime number
* @n: number
* @divisor: number to devide by
* Return: 1 if prime, 0 if not
*/

int is_prime(int n, int divisor)
{
	if (divisor <= 1)
		return (1);
	else if (n % divisor == 0)
		return (0);
	return (is_prime(n, divisor - 1));
}

/**
* is_prime_number - returns 1 if the integer is a prime number
* @n: number
* Return: 1 if prime, 0 if not
*/

int is_prime_number(int n)
{
	int divisor = n / 2;

	if (n <= 1)
		return (0);
	return (is_prime(n, divisor));
}
