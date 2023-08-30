#include "main.h"

/**
* wildcmp - returns 1 if the strings are identical
* @s1: string to be checked
* @s2: pattern to be used wildcmp
* Return: 1 if identical
* 0 if not
*/

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);
	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	return (0);
}
