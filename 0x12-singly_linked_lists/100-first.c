#include <stdio.h>

void __attribute__((constructor)) cnstr(void);
/**
 * cnstr- execute before the main function is executed.
 */
void cnstr(void)
{
	printf("You're beat! and yet, you must allow,\n"
	"I bore my house upon my back!\n");
}
