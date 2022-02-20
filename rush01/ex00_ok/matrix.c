/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:25:06 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 00:34:02 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct	s_data
{
	int	*array;
	int	index;
	int	size;
	int	**init;
	int	**matrix;
	int	**observers;
	int	n;
};

int	ft_check_row_work(struct s_data *in, int fixed_row, int in_col, int value)
{
	int	col;

	col = 0;
	while (col < in->n)
	{
		if (in->matrix[fixed_row][col] == value && col != in_col)
			return (0);
		col++;
	}
	return (1);
}

int	ft_check_col_work(struct s_data *in, int in_row, int fixed_col, int value)
{
	int	row;

	row = 0;
	while (row < in->n)
	{
		if (in->matrix[row][fixed_col] == value && row != in_row)
			return (0);
		row++;
	}
	return (1);
}

int	ft_check_row_init(struct s_data *in, int fixed_row, int in_col, int value)
{
	int	col;

	col = 0;
	while (col < in->n)
	{
		if (in->init[fixed_row][col] == value && col != in_col)
			return (0);
		col++;
	}
	return (1);
}

int	ft_check_col_init(struct s_data *in, int in_row, int fixed_col, int value)
{
	int	row;

	row = 0;
	while (row < in->n)
	{
		if (in->init[row][fixed_col] == value && row != in_row)
			return (0);
		row++;
	}
	return (1);
}

void	ft_copy_matrix(int **dest, int **src, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (src[i][j] != 0)
				dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
