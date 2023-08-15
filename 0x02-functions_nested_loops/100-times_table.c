#include "main.h"

/**
 * print_times_table - prints the n times table.
 * @n: integer value
 */

void print_times_table(int n)
{
	int i;
	int j;
	int multiplication;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				multiplication = (i * j);
				if (j == 0)
					_putchar('0' + multiplication);
				else
				{
					_putchar(',');
					_putchar(' ');
					if (multiplication <= 9)
					{
						_putchar(' ');
						_putchar(' ');
						_putchar('0' + multiplication);
					}
					else if (multiplication > 9 && multiplication < 100)
					{
						_putchar(' ');
						_putchar('0' + (multiplication / 10));
						_putchar('0' + (multiplication % 10));
					}
					else if (multiplication >= 100)
					{
						_putchar('0' + (multiplication / 100));
						_putchar('0' + ((multiplication / 10) % 10));
						_putchar('0' + (multiplication % 10));
					}
				}
			}
			_putchar('\n');
		}
	}
}
