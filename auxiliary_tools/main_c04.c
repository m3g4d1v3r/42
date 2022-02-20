/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:10:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/18 04:14:27 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FT_NULL_TEST (void *) 0
#define DEST_SIZE 100
#define FT_EXIT_SUCCESS 0
#define FT_EXIT_FAILURE 1
#define EX00_FILE "ex00/ft_strlen.c"
#define EX01_FILE "ex01/ft_putstr.c"
#define EX02_FILE "ex02/ft_putnbr.c"
#define EX03_FILE "ex03/ft_atoi.c"
#define EX04_FILE "ex04/ft_putnbr_base.c"
#define EX05_FILE "ex05/ft_atoi_base.c"

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_validate_base(char *base);
int		ft_atoi_base(char *str, char *base);

int	main(int argc, char *argv[])
{
	char	op_code;

	if (argc == 1)
		return (FT_EXIT_FAILURE);
	else if (argc != 2)
		return (FT_EXIT_FAILURE);
	op_code = atoi(argv[1]);
	if (op_code == 0)
	{
		#include EX00_FILE
		char test[] = "ABCDEFG";
		printf("expected: %d\n", (int) strlen(test));
		printf("actual: %d\n", ft_strlen(test));
		assert(ft_strlen(test) == (int) strlen(test));
	}
	else if (op_code == 1)
	{
		#include EX01_FILE
		ft_putstr("programming while listening to music is cool");
	}
	else if (op_code == 2)
	{
		#include EX02_FILE
		ft_putnbr(42);
		printf("\n");
		ft_putnbr(2147483647);
		printf("\n");
		ft_putnbr(-2147483648);
		printf("\n");
	}
	else if (op_code == 3)
	{
		#include EX03_FILE
		assert(ft_atoi("42") == atoi("42"));
		assert(ft_atoi("42") == 42);
		assert(ft_atoi("2147483647") == 2147483647);
		assert(ft_atoi("-2147483648") == -2147483648);
		assert(ft_atoi("     ---+--+1234ab567") == -1234);
	}
	else if (op_code == 4)
	{
		#include EX04_FILE
		ft_putnbr_base(42, "0123456789");         // 42
		printf("\n");
		ft_putnbr_base(421, "01");                // 110100101
		printf("\n");
		ft_putnbr_base(42, "0123456789ABCDEF");   // 2A
		printf("\n");
		ft_putnbr_base(-42, "0123456789ABCDEF");  // -2A
		printf("\n");
		ft_putnbr_base(4242, "poneyvif");         // opnnn
		printf("\n");
	}
	else if (op_code == 5)
	{
		#include EX05_FILE
		assert(ft_atoi_base("42", "0123456789") == 42);
		assert(ft_atoi_base("-42", "0123456789") == -42);
		assert(ft_atoi_base("-2147483648", "0123456789") == -2147483648);
		assert(ft_atoi_base("2147483647", "0123456789") == 2147483647);
		assert(ft_atoi_base("2A", "0123456789ABCDEF") == 42);
		assert(ft_atoi_base("opnnn", "poneyvif") == 4242);
	}
	return (FT_EXIT_SUCCESS);
}
