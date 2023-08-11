#include <stdio.h>

/**
 *main - prints all possible different combinations of two digits.
 *
 *Return: Always 0 (Success)
 */

int main(void)
{
	int firstdigit;
	int seconddigit;

	for (seconddigit = '0'; seconddigit <= '9'; seconddigit++)
	{
		for (firstdigit = (seconddigit + 1); firstdigit <= '9'; firstdigit++)
		{
			putchar(seconddigit);
			putchar(firstdigit);

			if (!(seconddigit == '8' && firstdigit == '9'))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
