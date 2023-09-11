#include "dog.h"
#include <stdlib.h>

/**
 *_strlen -  function that returns the length of a string.
 * @s: string value
 *Return: returns the length of a string.
 */
int _strlen(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
;

return (i);
}

/**
* _strcpy - Copy string
*@dest: destination
*@src: source
*Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to new dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dogg;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);
	dogg = malloc(sizeof(dog_t));
	if (!dogg)
		return (NULL);

	dogg->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!dogg->name)
	{
		free(dogg);
		return (NULL);
	}
	dogg->name = _strcpy(dogg->name, name);

	dogg->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (!dogg->owner)
	{
		free(dogg->name);
		free(dogg);
		return (NULL);
	}
	dogg->owner = _strcpy(dogg->owner, owner);

	dogg->age = age;

	return (dogg);
}
