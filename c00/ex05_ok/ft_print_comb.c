/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:12:48 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/06 05:10:40 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define STDOUT_FD 1
#define N 9

void	write_combination(int count_i, int count_j, int count_k)
{
	char	chr_i;
	char	chr_j;
	char	chr_k;

	chr_i = count_i + '0';
	chr_j = count_j + '0';
	chr_k = count_k + '0';
	write(STDOUT_FD, &chr_i, 1);
	write(STDOUT_FD, &chr_j, 1);
	write(STDOUT_FD, &chr_k, 1);
}

// Algorithm inspired by Bubble Sort mechanics!
void	ft_print_comb(void)
{
	int	count_i;
	int	count_j;
	int	count_k;

	count_i = 0;
	while (count_i <= N)
	{
		count_j = count_i + 1;
		while (count_j <= N)
		{
			count_k = count_j + 1;
			while (count_k <= N)
			{
				write_combination(count_i, count_j, count_k);
				if (!((count_i == 7) && (count_j == 8) && (count_k == 9)))
					write(STDOUT_FD, ", ", 2);
				count_k++;
			}
			count_j++;
		}
		count_i++;
	}
}
