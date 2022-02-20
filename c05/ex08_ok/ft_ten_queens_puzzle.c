/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:33:56 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/19 05:54:21 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define SIZE 10
#define EMPTY '_'
#define QUEEN 'Q'

int	ft_check_rows_and_diags(char board[SIZE][SIZE], int q_i, int q_j)
{
	int	coord;

	coord = 1;
	while (coord < SIZE)
	{
		if (board[(q_i + coord) % SIZE][q_j] == QUEEN)
			return (0);
		coord++;
	}
	coord = 1;
	while (((q_i + coord) < SIZE) && ((q_j + coord) < SIZE))
	{
		if (board[q_i + coord][q_j + coord] == QUEEN)
			return (0);
		coord++;
	}
	coord = 1;
	while (((q_i - coord) >= 0) && ((q_j + coord) < SIZE))
	{
		if (board[q_i - coord][q_j + coord] == QUEEN)
			return (0);
		coord++;
	}
	return (1);
}

int	ft_check_cols_and_diags(char board[SIZE][SIZE], int q_i, int q_j)
{
	int	coord;

	coord = 1;
	while (coord < SIZE)
	{
		if (board[q_i][(q_j + coord) % SIZE] == QUEEN)
			return (0);
		coord++;
	}
	coord = 1;
	while (((q_i + coord) < SIZE) && ((q_j - coord) >= 0))
	{
		if (board[q_i + coord][q_j - coord] == QUEEN)
			return (0);
		coord++;
	}
	coord = 1;
	while (((q_i - coord) >= 0) && ((q_j - coord) >= 0))
	{
		if (board[q_i - coord][q_j - coord] == QUEEN)
			return (0);
		coord++;
	}
	return (1);
}

void	ft_print_queens(char board[SIZE][SIZE], char *base)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		flag = 0;
		while (i < SIZE)
		{
			if (board[i][j] == QUEEN)
			{
				write(1, &base[i], 1);
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			write(1, "-", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	ft_deep_search(char board[SIZE][SIZE], int row, int column, int *res)
{
	int	offset;

	if (ft_check_rows_and_diags(board, row, column))
	{
		if (ft_check_cols_and_diags(board, row, column))
		{
			board[row][column] = QUEEN;
			if (column == SIZE - 1)
			{
				*res += 1;
				ft_print_queens(board, "0123456789");
				board[row][column] = EMPTY;
				return ;
			}
			offset = 1;
			while (offset <= SIZE)
			{
				ft_deep_search(board, (row + offset) % SIZE, column + 1, res);
				offset++;
			}
			board[row][column] = EMPTY;
		}
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	char	board[SIZE][SIZE];
	int		i;
	int		j;
	int		offset;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			board[i][j++] = EMPTY;
		}
		i++;
	}
	offset = 0;
	while (offset < SIZE)
	{
		ft_deep_search(board, offset++, 0, &res);
	}
	return (res);
}
