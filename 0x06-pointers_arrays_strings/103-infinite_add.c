#include <stdio.h>

/**
* max - funtion that return the max value
*@i:first number
*@j:second number
*Return: the max
*/

int max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

/**
* fill_empty - function that remove the first empty cells
*@r:the char table
*@size:the max size of table
*@size_r: the number of first empty cells
*Return: the reformed char table
*/

char *fill_empty(char *r, int size, int size_r)
{
	int i = 0;

	for (; i < size - size_r; i++)
	{
		*(r + i) = *(r + i + size_r + 1);
	}
	r[i] = '\0';
	i++;
	for (; i < size; i++)
	{
		*(r + i) = 0;
	}
	return (r);
}

/**
* goToLast - go to last index of char
*@c:the char table
*Return: the adress if last cell
*/

char *goToLast(char *c)
{
	while (*c != '\0')
	{
		c++;
	}
	return (c);
}

/**
* arrayLength - return the length of sting
*@c:the char table
*Return: the length of sting
*/

int arrayLength(char *c)
{
	int i = 0;

	while (*c != '\0')
	{
		i++;
	}
	return (i);
}
/**
* infinite_add - C function that adds two numbers
*@n1:first number
*@n2:second number
*@r: contains the result
*@size_r: is the buffer size
*Return: pointer to result
*/

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int sum = 0, size = --size_r, i = 0, j = 0, extra = 0;

	n1 = goToLast(n1);
	n2 = goToLast(n2);
	i = arrayLength(n1);
	j = arrayLength(n2);
	if (max(i, j) > size_r)
		return (0);
	n1--;
	n2--;
	for (; *n1 != '\0' && *n2 != '\0'; n1--, n2--, size_r--)
	{
		sum = (*n1 - '0') + (*n2 - '0') + extra;
		*(r + size_r) = (sum % 10) + '0';
		extra = sum / 10;
	}
	for (; *n1; n1--, size_r--)
	{
		sum = (*n1 - '0') + extra;
		*(r + size_r) = (sum % 10) + '0';
		extra = sum / 10;
	}
	for (; *n2; n2--, size_r--)
	{
		sum = (*n2 - '0') + extra;
		*(r + size_r) = (sum % 10) + '0';
		extra = sum / 10;
	}
	if (extra != 0)
	{
		*(r + size_r) = extra + '0';
		size_r--;
	}
	if (size_r < 0)
		return (0);
	fill_empty(r, size, size_r);
	return (r);
}
