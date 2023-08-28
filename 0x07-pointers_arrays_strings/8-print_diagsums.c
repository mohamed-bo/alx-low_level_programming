#include "main.h"

/**
*print_diagsums -  prints the sum of the two diagonals of matrix
*@a:matrix
*@size:size of the matrix
*/

void print_diagsums(int *a, int size)
{
	int i = 0, sumDiagonal = 0, sumRevDiagonal = 0;

	for (; i < size; i++)
	{
		sumDiagonal += a[i];
		a += size;
	}

	a -= size;

	for (i = 0; i < size; i++)
	{
		sumRevDiagonal += a[i];
		a -= size;
	}

	printf("%d, %d\n", sumDiagonal, sumRevDiagonal);
}
