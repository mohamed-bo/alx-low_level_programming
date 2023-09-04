#include "main.h"

/**
 *_strlen -  function that returns the length of a string.
 * @result: string value
 *Return: returns the length of a string.
 */
int _strlen(char *result)
{
int i;

for (i = 0; result[i] != '\0'; i++)
{
}

return (i);
}

/**
* argstostr - function that concatenates all the arguments of your program.
*@ac: size of av
*@av:array of arguments
*Return: pointer to the new string
*NULL if it fails
*/

char *argstostr(int ac, char **av)
{
	char *result;
	int size = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		size += _strlen(av[i]);
	size += (ac + 1); /* for newlines and null terminator */
	result = malloc(size * sizeof(char));

	if (result == NULL)
	{
		free(result);
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; j < _strlen(av[i]); j++)
		{
			result[k++] = av[i][j];
		}
		result[k++] = '\n';
	}
	result[k] = '\0';

	return (result);
}
