#include "main.h"

/**
* alloc_grid - a pointer to a 2 dimensional array of integers.
*@width: width oàf matrix
*@height: height of matrix
*Return: pointer to the matrix
*/

int **alloc_grid(int width, int height)
{
	int **matrix;
	int i = 0, j;

	if (width == 0 || height == 0)
		return (NULL);
	matrix = (int **) malloc(sizeof(int *) * height);
	if (matrix == NULL)
		return (NULL);

	for (; i < height; i++)
	{
		matrix[i] = (int *) malloc(sizeof(int) * width);
		if (matrix[i] != NULL)
		{
			for (j = 0; j < width; j++)
				matrix[i][j] = 0;
		}
		else
		{
			while (i >= 0)
			{
				free(matrix[i]);
				i--;
			}
			free(matrix);
			return (NULL);
		}
	}
	return (matrix);

}
