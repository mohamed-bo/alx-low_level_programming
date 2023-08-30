#include "main.h"

/**
 * checkPalindrome - campare start and end indices
 * @start: index starting from left
 * @end: index starting from right
 * Return: 1 if palindrome
 * 0 if not
 */

int checkPalindrome(char *start, char *end)
{

	if (start >= end)
		return (1);
	if (*start == *end)
		return (checkPalindrome(start + 1, end - 1));

	return (0);
}

/**
 * _strlen - length of string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{

	if (*s == '\0')
		return (0);
	return (1 + (_strlen(s + 1)));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome
 * @s: string
 * Return: 1 if palindrome
 * 0 if not
 */

int is_palindrome(char *s)
{
	int len = _strlen(s);

	return (checkPalindrome(s, (s + len - 1)));
}
