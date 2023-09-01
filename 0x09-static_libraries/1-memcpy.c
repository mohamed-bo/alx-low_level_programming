#include "main.h"
/**
*_memcpy - copies n bytes from memory area src to memory area dest
*@dest:adress of area where we are copying to
*@src:adress of area where we copying from
*@n:number of bytes
*Return: returns a pointer to area we copied to
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	while (n)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
	return (dest);
}
