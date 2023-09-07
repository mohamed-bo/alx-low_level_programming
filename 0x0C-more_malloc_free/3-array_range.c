#include "main.h"
#include <stdlib.h>

/**
 * array_range -  creates an array of integers
 * similair to aragne function in python
 * @min: minimum value
 * @max: maximum value
 * Return: pointer to the result
 */
int *array_range(int min, int max)
{
	int *result;
	int i;

	if (min > max)
		return (NULL);

	result = malloc(sizeof(int) * (max - min + 1));
	if (result == NULL)
		return (NULL);

	for (i = min; i <= max; i++)
		result[i] = min + i;

	return (result);
}
