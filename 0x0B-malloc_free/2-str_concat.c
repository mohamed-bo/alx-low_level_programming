#include "main.h"

/**
* str_concat - a function that concatenates two strings.
*@s1:First string
*@s2:Second string
*Return: NULL if fails
*pointer if it success
*/

char *str_concat(char *s1, char *s2)
{
	char *concat;
	int size1 = 0, size2 = 0, i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s1 + i))
		size1++, i++;
	while (*(s2 + j))
		size2++, j++;

	concat = malloc(sizeof(char) * (size1 + size2 + 1));

	if (concat == NULL)
		return (NULL);

	i = 0, j = 0;
	while (i < size1)
	{
		*(concat + i) = *(s1 + i);
		i++;
	}
	while (j < size2)
	{
		*(concat + i) = *(s2 + j);
		i++, j++;
	}
	*(concat + i) = '\0';

	return (concat);
}
