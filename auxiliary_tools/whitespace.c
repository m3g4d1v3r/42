#include <stdio.h>

int main()
{
	printf("chr: %c, int: %d\n", ' ', (int) ' ');
	for (int cont = '\t'; cont <= '\r'; cont++)
		printf("chr: %c, int: %d\n", cont, (int) cont);
}