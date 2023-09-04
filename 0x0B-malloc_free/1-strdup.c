#include "main.h"

/**
* _strdup - returns a pointer to a newly allocated space in memory
*which contains a copy of the string given as a parameter
*@str:String to copy
*Return: NULL if error
*pointer if it success
*/

char *_strdup(char *str)
{
	char *duplicate;
	int i = 0, size = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		size++;
	duplicate = malloc(sizeof(char) * (size + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}

	duplicate[size] = '\0';

	return (duplicate);

}
