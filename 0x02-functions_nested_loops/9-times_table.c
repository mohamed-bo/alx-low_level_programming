#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 */

void times_table(void)
{
	int i;
	int j;
	int multiplication;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			multiplication = (i * j);

			if (j == 0)
			{
				_putchar('0' + multiplication);
			}
			else if (multiplication <= 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + multiplication);
			}
			else if (multiplication > 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar('0' + (multiplication / 10));
				_putchar('0' + (multiplication % 10));
			}
		}
		_putchar('\n');
	}
}
