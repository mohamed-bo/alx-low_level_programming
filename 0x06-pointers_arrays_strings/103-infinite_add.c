#include <stdio.h>

/**
* infinite_add - C function that adds two numbers
*@n1:first number
*@n2:second number
*@r: contains the result
*@size_r: is the buffer size
*Return: pointer to result
*/

int max(int i,int j)
{
if (i > j)
		return (i);
	else
		return (j);
}
char *fill_empty(char *r, int size, int size_r)
{
	int i = 0;
for(; i< size - size_r ;i++)
	{
		*(r + i)=*(r +i+ size_r+1);
	}
	r[i] = '\0';
	i++;
	return (r);
}
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int sum = 0, size = --size_r, i = 0, j = 0, extra = 0;
	while (*n1 != '\0')
	{
		i++;
		n1++;
	}
	while (*n2 != '\0')
	{
		j++;
		n2++;
	}
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
	for (; *n1; n1-- , size_r--)
	{
		sum = (*n1 - '0') + extra; 
		*(r + size_r) = (sum % 10) + '0';
		extra = sum / 10;
	}
	for (; *n2; n2-- ,  size_r--)
	{
		sum = (*n2 - '0') + extra; 
		*(r + size_r) = (sum % 10) + '0';
		extra = sum / 10; 
	}
	if (extra !=0)
	{
		*(r + size_r) = extra + '0';
        size_r--; 
	}
	if (size_r<0)
		return (0);
	fill_empty(r,size,size_r);
    return (r);
}
