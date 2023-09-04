#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *_strlen -  function that returns the length of a string.
 *@result: string value
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
 *duplicate_word - create a ponter to char contains word
 *@str: string to copy in new adress
 *@start: start arrayIndex
 *@end: end arrayIndex
 *Return: pointer to new word
 */

char *duplicate_word(char *str, int start, int end)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);

	for (i = 0; i < end - start; i++)
		word[i] = str[start + i];

	word[i] = '\0';
	return (word);
}

/**
 * words_number - counts the number of words in a string
 * @str: string
 * Return: number of words
 */
int words_number(char *str)
{
	int wordsNumber = 0, i, size;

	if (!str || !str[0])
		return (0);

	size = _strlen(str);

	for (i = 0; i < size; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			wordsNumber++;
	}

	return (wordsNumber);
}

/**
 * strtow - splits a string into words.
 * @str: string
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int wordsNumber, size, arrayIndex = 0;
	int i, start = 0, end;

	wordsNumber = words_number(str);
	if (wordsNumber == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wordsNumber + 1));
	if (!words)
		return (NULL);
	size = _strlen(str);
	for (i = 0; i < size; i++)
	{
		if (str[i] != ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			continue;
		else if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			end = i + 1;
			words[arrayIndex] = duplicate_word(str, start, end);
			if (!words[arrayIndex])
			{
				while (i > -1)
				{
					free(words[i]);
					i--;
				}
				free(words);
			}
			arrayIndex++;
		}
		else
			start = i + 1;
	}

	return (words);
}
