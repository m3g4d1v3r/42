/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:10:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 21:45:54 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define EX00_FILE "ex00/ft_putchar.c"
#define EX01_FILE "ex01/ft_print_alphabet.c"
#define EX02_FILE "ex02/ft_print_reverse_alphabet.c"
#define EX03_FILE "ex03/ft_print_numbers.c"
#define EX04_FILE "ex04/ft_is_negative.c"
#define EX05_FILE "ex05/ft_print_comb.c"
#define EX06_FILE "ex06/ft_print_comb2.c"
#define EX07_FILE "ex07/ft_putnbr.c"
#define EX08_FILE "ex08/ft_print_combn.c"

int	main(int argc, char *argv[])
{
	#include EX01_FILE
	//ft_putchar(argv[1][0]);
	ft_print_alphabet();
	//ft_print_reverse_alphabet();
	//ft_print_numbers();
	//ft_is_negative(atoi(argv[2]));
	//ft_print_comb();
	//ft_print_comb2();
	//ft_putnbr(atoi(argv[2]));
	//ft_print_combn(atoi(argv[2]));
	(void) argc;
	(void) argv;
	return (0);
}
