#include "main.h"
int main(void)
{
	int n = -45, m = 45;
	char c = 'F';
	char *s = "Is it working";
	_printf("This is test for octal %o string %s hex %X,%x and binary %b character %c Bufer\n", n, s, n, n, n, c);
	_printf("This is test for octal %o string %s hex %X,%x and binary %b character %c Bufer\n", m, s, m, m, m, c);
	printf("%d, %X, %o, %o\n", n, n, n, n);
	printf("%d, %X, %o, %o\n", m, m, m, m);
	return (0);
}
