#include "main.h"

/**
* cap_string - capitalizes all first word in phrase.
* @s: string
* Return: string capitalized
*/

char *cap_string(char *s)
{
	int i = 0;

	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= 32;
	i++;

	while (s[i] != '\0')
	{

		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] == ',' || s[i - 1] == ';' ||
		s[i - 1] == '.' ||	s[i - 1] == '!' || s[i - 1] == '?' ||
		s[i - 1] == '"' ||	s[i - 1] == '(' || s[i - 1] == ')' ||
		s[i - 1] == '{' ||	s[i - 1] == '}' || s[i - 1] == ' ' ||
		s[i - 1] == '\t' || s[i - 1] == '\n'))
			s[i] -= 32;
		i++;
	}

	return (s);
}
