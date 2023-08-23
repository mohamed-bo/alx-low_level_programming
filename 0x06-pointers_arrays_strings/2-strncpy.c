#include "main.h"
/**
* _strncpy - copies a string, including the at most specefic n number
*@dest: the result string or the main String
*@src: String that we are copying
*@n: max nummber of byte copied
*Return: a pointer to the resulting string dest
*/

char *_strncpy(char *dest, char *src, int n)
{

	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);

}
