#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a character
 * @agruments: va_list contains the char
 */
void print_char(va_list agruments)
{
	printf("%c", va_arg(agruments, int));
}

/**
 * print_int - prints an integer
 * @agruments: va_list contains the int
 */
void print_int(va_list agruments)
{
	printf("%d", va_arg(agruments, int));
}

/**
 * print_float - prints a float
 * @agruments: va_list contains the float
 */
void print_float(va_list agruments)
{
	printf("%f", va_arg(agruments, double));
}

/**
 * print_string - prints a string
 * @agruments: va_list contains the string
 */
void print_string(va_list agruments)
{
	char *s = va_arg(agruments, char*);

	printf("%s", s == NULL ? "(nil)" : s);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list agruments;
	int i = 0, j;
	char *seperator = "";

	printType print[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
	};

	va_start(agruments, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4 && format[i] != print[j].type[0])
			++j;
		if (j < 4)
		{
			printf("%s", seperator);
			print[j].func(agruments);
			seperator = ", ";
		}
		++i;
	}
	printf("\n");
	va_end(agruments);
}
