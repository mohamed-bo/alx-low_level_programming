#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 * and set the memory to 0
 * @nmemb: size of array
 * @size: size of each element
 * Return: pointer to the result
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *result;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		result[i] = 0;

	return (result);
}
