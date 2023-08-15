#include <stdio.h>

/**
 * main - sum of the even-valued terms up to 4,000,000
 * Return: 0
 */

int main(void)
{
	int sum_of_evens = 0;
	int i = 1;
	long f = 1;
	long s = 1;

	while (i <= 4000000)
	{
		f = s;
		s = i;
		i = s + f;
		if ((i <= 4000000) && (i % 2 == 0))
			sum_of_evens += i;
	}
	printf("%d\n", sum_of_evens);

	return (0);
}
