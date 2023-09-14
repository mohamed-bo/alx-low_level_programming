#ifndef _VARIADIC_FUNCTIONS_H_
#define _VARIADIC_FUNCTIONS_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * struct printType - struct containt function of types
 * @type: type
 * @func: function of exact type
 */
typedef struct printType
{
	char *type;
	void (*func)(va_list);
} printType;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
