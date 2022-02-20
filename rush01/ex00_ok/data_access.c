/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:59:39 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 01:30:28 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_check_row_work(struct s_data *in, int fixed_row, int in_col, int value);
int	ft_check_col_work(struct s_data *in, int in_row, int fixed_col, int value);
int	ft_check_row_init(struct s_data *in, int fixed_row, int in_col, int value);
int	ft_check_col_init(struct s_data *in, int in_row, int fixed_col, int value);

int	ft_sudoku_available(struct s_data *in, int value)
{
	int	temp_index;
	int	row;
	int	col;

	temp_index = in->index;
	row = temp_index / in->n;
	col = temp_index % in->n;
	if (ft_check_row_work(in, row, col, value) == 0)
		return (0);
	if (ft_check_col_work(in, row, col, value) == 0)
		return (0);
	if (ft_check_row_init(in, row, col, value) == 0)
		return (0);
	if (ft_check_col_init(in, row, col, value) == 0)
		return (0);
	return (1);
}

int	ft_get_init_matrix_value(struct s_data *in)
{
	int	temp_index;
	int	row;
	int	col;

	temp_index = in->index;
	row = temp_index / in->n;
	col = temp_index % in->n;
	return (in->init[row][col]);
}

int	ft_get_work_matrix_value(struct s_data *in)
{
	int	temp_index;
	int	row;
	int	col;

	temp_index = in->index;
	row = temp_index / in->n;
	col = temp_index % in->n;
	return (in->matrix[row][col]);
}
