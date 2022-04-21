int main()
{
	#include <stdio.h>
	char	**dict_ptr;
	char	*dict[] = {
		"coffee",
		"energy soda",
		"metal",
		"john wick",
		"\x00"
	};

	dict_ptr = dict;
	while (**dict_ptr)
	{
		printf("%s\n", *dict_ptr);
		dict_ptr++;
	}
}
