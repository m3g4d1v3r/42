/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:12:48 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 16:52:11 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define STDOUT_FD 1
#define MAX_I 99
#define MAX_J 99
#define TRUE 1
#define FALSE 0

void	set_algarisms(char *str, int value)
{
	str[0] = value / 10;
	str[1] = value - str[0] * 10;
	str[0] = str[0] + '0';
	str[1] = str[1] + '0';
}

void	write_tuple(int value_i, int value_j)
{
	char	array_i[2];
	char	array_j[2];

	set_algarisms(array_i, value_i);
	set_algarisms(array_j, value_j);
	write(STDOUT_FD, array_i, 2);
	write(STDOUT_FD, " ", 1);
	write(STDOUT_FD, array_j, 2);
}

void	ft_print_comb2(void)
{
	int	count_i;
	int	count_j;
	int	flag_break;

	count_i = 0;
	count_j = 1;
	flag_break = FALSE;
	while (count_i <= MAX_I)
	{
		if (count_i >= 1)
			count_j = count_i + 1;
		while (count_j <= MAX_J)
		{
			write_tuple(count_i, count_j);
			if ((count_i == (MAX_I - 1)) && (count_j == MAX_J))
				flag_break = TRUE;
			else
				write(STDOUT_FD, ", ", 2);
			count_j++;
		}
		if (flag_break)
			break ;
		count_i++;
	}
}
