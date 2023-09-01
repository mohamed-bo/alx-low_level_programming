#include "main.h"
/**
*_strspn - gets the length of a prefix substring.
*@s:string we are shearching in
*@accept:characters we are looked for
*Return:the number of bytes in the initial
* segment of s which consist only of bytes from accept
*/
unsigned int _strspn(char *s, char *accept)
{
	int matches = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (accept[i] == *s)
			{
				matches++;
				break;
			}
			else if ((accept[i + 1]) == '\0')
				return (matches);
		}
		s++;
	}
	return (matches);
}
