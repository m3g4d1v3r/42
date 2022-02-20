#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *array;
	array = malloc(sizeof(int *) * 4);
	int i = 0;
	while (i++ < 4)
	{
		*(array + i) = i;
		printf("%d\n", *(array + i));
	}
	return (0);
}