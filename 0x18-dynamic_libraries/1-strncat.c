#include "main.h"
/**
 *_strncat - append specefic n of character from src to dest
 *@dest: main String that we append to
 *@src: String to appended to dest
 *@n: number of character to append
 *Return: a pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{

	int i = 0, dest_index = 0;

	while (dest[i++])
		dest_index++;

	for (i = 0; src[i] && i < n; i++)
		dest[dest_index++] = src[i];

	return (dest);

}
