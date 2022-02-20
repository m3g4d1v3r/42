#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int size;

	if (argc < 2)
		return (-1);
	size = atoi(argv[1]);
	while (size--)
		printf("%d\n", size);
}