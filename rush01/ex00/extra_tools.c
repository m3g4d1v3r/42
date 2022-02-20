/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 07:01:16 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 02:43:40 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define STDOUT_FD 1
#define MAX_BUFFER 10000

int	ft_itoa(char *str, int value);

void	ft_print_array(int *array, int n)
{
	char	to_print_str[MAX_BUFFER];
	int		index;
	int		size;

	index = 0;
	while (index < n)
	{
		size = ft_itoa(to_print_str, array[index++]);
		write(STDOUT_FD, to_print_str, sizeof(char) * size);
		write(STDOUT_FD, " ", sizeof(char) * 1);
	}
	write(STDOUT_FD, "\n", sizeof(char) * 1);
}

void	ft_print_matrix(int **matrix, int n)
{
	char	to_print_str[MAX_BUFFER];
	int		size;
	int		row;
	int		col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			size = ft_itoa(to_print_str, matrix[row][col]);
			write(STDOUT_FD, to_print_str, sizeof(char) * size);
			if (col != (n - 1))
				write(STDOUT_FD, " ", sizeof(char) * 1);
			col++;
		}
		write(STDOUT_FD, "\n", sizeof(char) * 1);
		row++;
	}
}
