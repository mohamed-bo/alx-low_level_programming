#include "main.h"
/**
*_strchr - locates a character in a string.
*@s:string we are shearching in
*@c:character targeted we are looked for
*Return: a pointer to the first occurrence of the character c
*/
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; (s[i] != '\0') && (s[i] != c); i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
