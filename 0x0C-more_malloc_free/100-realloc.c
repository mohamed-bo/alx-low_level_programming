#include "main.h"
#include <stdlib.h>
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

/**
* _realloc -  reallocates a memory block using malloc and free
* @ptr: pointer to the memory previously allocated
* @old_size: size of ptr
* @new_size: size of the new memory block
* Return: pointer to the result
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);

	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block == NULL)
			return (NULL);
		for (i = 0; i < min(old_size, new_size); i++)
		*((char *)temp_block + i) = *((char *) ptr + i);
		free(ptr);
		return (temp_block);
	}
}
