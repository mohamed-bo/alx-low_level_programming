#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *pass = malloc(sizeof(char) * 5);
	char c[5] = {'H', 'o', 'l', 4, '\0'}, run[100];
	int i;

	for (i = 0; c[i]; i++)
		pass[i] = c[i];

	pass[i] = '\0';
	printf("%s", pass);

	return (0);
}
