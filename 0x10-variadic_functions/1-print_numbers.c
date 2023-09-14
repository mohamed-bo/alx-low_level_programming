#include "variadic_functions.h"

/**
 * print_numbers - prints numbers and seperator
 * @separator: seperator between strings
 * @n: number of agruments
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list agruments;
	unsigned int i;

	va_start(agruments, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(agruments, int));
		if (separator != NULL && i != (n - 1))
		{
			printf("%s", separator);
		}
	}
	putchar('\n');
	va_end(agruments);
}
