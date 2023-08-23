#include "main.h"

/**
 *_strcat - appends the src string to the dest string
 *@dest: main String that we append to
 *@src: String to appended to dest
 *Returns a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{

	int i = 0, dest_index = 0;

	while (dest[i++])
		dest_index++;

	for (i = 0; src[i]; i++)
	{
		dest[dest_index] = src[i];
		dest_index++;
	}
	return (dest);
}
