#include <stdio.h>

/**
 *main - prints all possible combinations of two two-digit numbers.
 *Return: Always 0 (Success)
 */

int main(void)
{
	int fourth;
	int third;
	int second;
	int first;
	int temp;

	for (fourth = '0'; fourth <= '9'; fourth++)
	{
		for (third = '0'; third <= '9'; third++)
		{
			for (second = fourth; second <= '9'; second++)
			{
				if (third != temp)
				{
					first = third + 1;
					temp = third;
				}
				else
					first = '0';
				for (; first <= '9'; first++)
				{
					putchar(fourth);
					putchar(third);
					putchar(' ');
					putchar(second);
					putchar(first);

					if (!(fourth == '9' && third == '8' && second == '9' && first == '9'))
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
