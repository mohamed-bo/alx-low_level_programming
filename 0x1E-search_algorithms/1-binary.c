#include "search_algos.h"

/**
 * recursiveBinary - search recursivly
 *
 * @array: array
 * @size: size of array
 * @value: value
 * Return: index of the value
 */
int recursiveBinary(int *array, size_t size, int value)
{
	size_t mid = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array");
	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);
	printf("\n");
	if (mid && size % 2 == 0)
		mid--;
	if (value == array[mid])
		return ((int)mid);
	if (value < array[mid])
		return (recursiveBinary(array, mid, value));
	mid++;
	return (recursiveBinary(array + mid, size - mid, value) + mid);
}

/**
 * binary_search - calls recursive function
 *
 * @array: array
 * @size: size of array
 * @value: value
 * Return: index of the value
 */
int binary_search(int *array, size_t size, int value)
{
	int i;

	i = recursiveBinary(array, size, value);
	if (i >= 0 && array[i] != value)
		return (-1);
	return (i);
}
