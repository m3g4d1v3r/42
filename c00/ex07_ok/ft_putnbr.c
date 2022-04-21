/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:12:48 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 05:22:18 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define DIVISOR 10
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define STDOUT_FD 1
#define TRUE 1
#define FALSE 0
#define BUFFER_MAX 12

void	ft_swap(char *str, int index_1, int index_2)
{
	char	aux_var;

	aux_var = str[index_1];
	str[index_1] = str[index_2];
	str[index_2] = aux_var;
}

void	ft_reverse_string(char *str, int size)
{
	int		string_index;

	string_index = 0;
	while (string_index < size / 2)
	{
		ft_swap(str, string_index, size - string_index - 1);
		string_index++;
	}
}

void	ft_negative_header(int *nb, int *is_negative, int *is_min, int *index)
{
	if (*nb < 0)
	{
		if (*nb == INT_MIN)
		{
			*is_min = TRUE;
			*nb = *nb + 1;
		}
		*nb = -1 * *nb;
		*is_negative = TRUE;
		*index = 1;
	}
}

void	ft_negative_footer(char *buffer, int is_negative, int is_min, int index)
{
	if (is_negative)
	{
		ft_reverse_string(&buffer[1], index - 1);
		if (is_min)
			buffer[index - 1]++;
		buffer[0] = '-';
	}
	else
		ft_reverse_string(buffer, index);
}

void	ft_putnbr(int nb)
{
	char	buffer[BUFFER_MAX];
	int		index;
	int		is_negative;
	int		is_min;

	index = 0;
	is_negative = FALSE;
	is_min = FALSE;
	ft_negative_header(&nb, &is_negative, &is_min, &index);
	if (nb == 0)
	{
		buffer[0] = '0';
		index++;
	}
	while (nb != 0)
	{
		buffer[index] = nb % DIVISOR + '0';
		nb = nb / DIVISOR;
		index++;
	}
	ft_negative_footer(buffer, is_negative, is_min, index);
	write(1, buffer, index);
}
