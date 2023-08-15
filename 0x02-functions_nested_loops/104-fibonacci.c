#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	unsigned long f = 1;
	unsigned long s = 1;
	unsigned long sum = 0;
	int counter;
	
	long oversum, f_part1, f_part2, s_part1, s_part2, sum_part1, sum_part2;

	printf("1");

	for (counter = 2; counter < 92; counter++)
	{
		sum = f + s;
		f = s;
		s = sum;
		printf(", %ld", sum);
	}

	f_part1 = f / 1000000000;
	f_part2 = f % 1000000000;
	s_part1 = s / 1000000000;
	s_part2 = s % 1000000000;

	for (; counter < 99; counter++)
	{
		oversum = (f_part2 + s_part2) / 1000000000;
		sum_part2 = (f_part2 + s_part2) - (1000000000 * oversum);
		sum_part1 = (f_part1 + s_part1) + oversum;

		printf(", %ld%ld", sum_part1, sum_part2);

		f_part1 = s_part1;
		f_part2 = s_part2;
		s_part1 = sum_part1;
		s_part2 = sum_part2;
	}


	printf("\n");

	return (0);
}
