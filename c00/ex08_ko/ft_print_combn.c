/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:12:48 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 20:59:29 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define STDOUT_FD 1
#define MAX_I 99
#define MAX_J 99
#define MAX_BUFFER 10
#define TRUE 1
#define FALSE 0
#define DIVISOR 10

struct	s_combn_data
{
	long long	count_i;
	long long	count_j;
	int			flag_break;
	int			max_limit;
};

int	ft_get_algarisms(long long input, int size)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		counter++;
		if (input / 10 == 0)
			break ;
		input /= 10;
	}
	return (counter);
}

void	itoa(char *str, long long nb, int size)
{
	int	index;
	int	algs;

	index = 0;
	algs = ft_get_algarisms(nb, size);
	while (index < (size - algs))
	{
		str[index] = '0';
		index++;
	}
	while (index < size)
	{
		str[index] = nb % DIVISOR + '0';
		nb = nb / DIVISOR;
		index++;
		if (nb == 0)
			break ;
	}
	return ;
}

void	ft_write_tuple_n(long long value_i, long long value_j, int size)
{
	char	array_i[MAX_BUFFER];
	char	array_j[MAX_BUFFER];

	itoa(array_i, value_i, size);
	itoa(array_j, value_j, size);
	write(STDOUT_FD, array_i, size);
	write(STDOUT_FD, " ", 1);
	write(STDOUT_FD, array_j, size);
}

void	ft_initialize_data(struct s_combn_data *current_data, int input)
{
	long long	nb;
	int			counter;

	current_data->count_i = 0;
	current_data->count_j = 1;
	current_data->flag_break = FALSE;
	nb = 1;
	counter = 0;
	while (counter < input)
	{
		nb *= 10;
		counter++;
	}
	current_data->max_limit = nb;
}

void	ft_print_combn(int n)
{
	struct s_combn_data	data;

	ft_initialize_data(&data, n);
	while (data.count_i < data.max_limit)
	{
		if (data.count_i >= 1)
			data.count_j = data.count_i + 1;
		while (data.count_j < data.max_limit)
		{
			ft_write_tuple_n(data.count_i, data.count_j, n);
			if (data.count_i == (data.max_limit - 2))
			{
				if (data.count_j == (data.max_limit - 1))
					data.flag_break = TRUE;
			}
			else
				write(STDOUT_FD, ", ", 2);
			data.count_j++;
		}
		if (data.flag_break)
			break ;
		data.count_i++;
	}
}
