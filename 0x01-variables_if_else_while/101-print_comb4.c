#include <stdio.h>

/**
 *main - print all combinations of three different digits
 *Return: Always 0 (Success)
 */

int main(void)
{
	int firstdigit;
	int seconddigit;
	int thirddigit;

	for (thirddigit = '0'; thirddigit <= '9'; thirddigit++)
	{
		for (seconddigit = (thirddigit + 1); seconddigit <= '9'; seconddigit++)
		{
			for (firstdigit = (seconddigit + 1); firstdigit <= '9'; firstdigit++)
			{
				putchar(thirddigit);
				putchar(seconddigit);
				putchar(firstdigit);
				if (thirddigit != '7' || seconddigit != '8' || firstdigit != '9')
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
