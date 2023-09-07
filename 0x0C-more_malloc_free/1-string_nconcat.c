#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat -  concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of first n bytes of s2
 * Return: pointer to result
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int i, j, size1, size2;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (size1 = 0; s1[size1]; size1++)
		;
	for (size2 = 0; s2[size2]; size2++)
		;

	n >= size2 ? n = size2 : n;

	result = malloc(sizeof(char) * (size1 + n + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		result[i] = s1[i];
	for (j = 0; j < n; j++)
		result[i + j] = s2[j];

	result[i + j] = '\0';

	return (result);
}
