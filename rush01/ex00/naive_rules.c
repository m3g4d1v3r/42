/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 08:24:04 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/13 14:13:27 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_COL_UP 0
#define FT_COL_DOWN 1
#define FT_ROW_LEFT 2
#define FT_ROW_RIGHT 3

void	ft_up_2_down(int **matrix, int **observers, int fixed_col, int n)
{
	int	row;
	int	observer;
	int	opposing_observer;

	observer = observers[FT_COL_UP][fixed_col];
	opposing_observer = observers[FT_COL_DOWN][fixed_col];
	if (observer == 1)
	{
		matrix[0][fixed_col] = n;
		if (opposing_observer == 2)
		{
			matrix[n - 1][fixed_col] = n - 1;
		}
	}
	else if (observer == n)
	{
		row = 0;
		while (row < n)
		{
			matrix[row][fixed_col] = row + 1;
			row++;
		}
	}
}

void	ft_down_2_up(int **matrix, int **observers, int fixed_col, int n)
{
	int	row;
	int	observer;
	int	opposing_observer;

	observer = observers[FT_COL_DOWN][fixed_col];
	opposing_observer = observers[FT_COL_UP][fixed_col];
	if (observer == 1)
	{
		matrix[n - 1][fixed_col] = n;
		if (opposing_observer == 2)
		{
			matrix[0][fixed_col] = n - 1;
		}
	}
	else if (observer == n)
	{
		row = 0;
		while (row < n)
		{
			matrix[n - row - 1][fixed_col] = row + 1;
			row++;
		}
	}
}

void	ft_left_2_right(int **matrix, int **observers, int fixed_row, int n)
{
	int	col;
	int	observer;
	int	opposing_observer;

	observer = observers[FT_ROW_LEFT][fixed_row];
	opposing_observer = observers[FT_ROW_RIGHT][fixed_row];
	if (observer == 1)
	{
		matrix[fixed_row][0] = n;
		if (opposing_observer == 2)
		{
			matrix[fixed_row][n - 1] = n - 1;
		}
	}
	else if (observer == n)
	{
		col = 0;
		while (col < n)
		{
			matrix[fixed_row][col] = col + 1;
			col++;
		}
	}
}

void	ft_right_2_left(int **matrix, int **observers, int fixed_row, int n)
{
	int	col;
	int	observer;
	int	opposing_observer;

	observer = observers[FT_ROW_RIGHT][fixed_row];
	opposing_observer = observers[FT_ROW_LEFT][fixed_row];
	if (observer == 1)
	{
		matrix[fixed_row][n - 1] = n;
		if (opposing_observer == 2)
		{
			matrix[fixed_row][0] = n - 1;
		}
	}
	else if (observer == n)
	{
		col = 0;
		while (col < n)
		{
			matrix[fixed_row][n - col - 1] = col + 1;
			col++;
		}
	}
}

void	ft_fill_naive(int **matrix, int **observers, int n)
{
	int	line;

	line = 0;
	while (line < n)
	{
		ft_up_2_down(matrix, observers, line, n);
		ft_down_2_up(matrix, observers, line, n);
		ft_left_2_right(matrix, observers, line, n);
		ft_right_2_left(matrix, observers, line, n);
		line++;
	}
}
