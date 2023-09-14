#include "variadic_functions.h"

/**
 * print_strings - prints strings and seperator
 * @separator: seperator between strings
 * ... : strings
 * @n: number of agruments
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list agruments;
	unsigned int i;
	char *str;

	va_start(agruments, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(agruments, char *);
		printf("%s", (str == NULL) ? "(nil)" : str);
		if (separator != NULL && i != (n - 1))
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(agruments);
}
