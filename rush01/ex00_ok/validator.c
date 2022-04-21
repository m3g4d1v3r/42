/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:19:21 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/13 09:55:05 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_COL_UP 0
#define FT_COL_DOWN 1
#define FT_ROW_LEFT 2
#define FT_ROW_RIGHT 3

int	ft_validate_up_2_down(int **matrix, int **observers, int f_col, int n)
{
	int	observer;
	int	obstacle_count;
	int	last_height;
	int	row;

	observer = observers[FT_COL_UP][f_col];
	obstacle_count = 0;
	last_height = 0;
	row = 0;
	while (row < n)
	{
		if (matrix[row][f_col] > last_height)
		{
			last_height = matrix[row][f_col];
			obstacle_count++;
		}
		row++;
	}
	return (observer == obstacle_count);
}

int	ft_validate_down_2_up(int **matrix, int **observers, int f_col, int n)
{
	int	observer;
	int	obstacle_count;
	int	last_height;
	int	row;

	observer = observers[FT_COL_DOWN][f_col];
	obstacle_count = 0;
	last_height = 0;
	row = 0;
	while (row < n)
	{
		if (matrix[n - row - 1][f_col] > last_height)
		{
			last_height = matrix[n - row - 1][f_col];
			obstacle_count++;
		}
		row++;
	}
	return (observer == obstacle_count);
}

int	ft_validate_left_2_right(int **matrix, int **observers, int f_row, int n)
{
	int	observer;
	int	obstacle_count;
	int	last_height;
	int	col;

	observer = observers[FT_ROW_LEFT][f_row];
	obstacle_count = 0;
	last_height = 0;
	col = 0;
	while (col < n)
	{
		if (matrix[f_row][col] > last_height)
		{
			last_height = matrix[f_row][col];
			obstacle_count++;
		}
		col++;
	}
	return (observer == obstacle_count);
}

int	ft_validate_right_2_left(int **matrix, int **observers, int f_row, int n)
{
	int	observer;
	int	obstacle_count;
	int	last_height;
	int	col;

	observer = observers[FT_ROW_RIGHT][f_row];
	obstacle_count = 0;
	last_height = 0;
	col = 0;
	while (col < n)
	{
		if (matrix[f_row][n - col - 1] > last_height)
		{
			last_height = matrix[f_row][n - col - 1];
			obstacle_count++;
		}
		col++;
	}
	return (observer == obstacle_count);
}

int	ft_validate_matrix(int **matrix, int **observers, int n)
{
	int	line;
	int	v_bool[4];

	line = 0;
	while (line < n)
	{
		v_bool[0] = ft_validate_up_2_down(matrix, observers, line, n);
		v_bool[1] = ft_validate_down_2_up(matrix, observers, line, n);
		v_bool[2] = ft_validate_left_2_right(matrix, observers, line, n);
		v_bool[3] = ft_validate_right_2_left(matrix, observers, line, n);
		if (!(v_bool[0] && v_bool[1] && v_bool[2] && v_bool[3]))
			return (0);
		line++;
	}
	return (1);
}
