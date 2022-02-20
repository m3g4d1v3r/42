/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:56:59 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/13 06:57:22 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_allocate_array(int n_elements)
{
	return (malloc(sizeof(int) * n_elements));
}

int	**ft_allocate_matrix(int n)
{
	int	row;
	int	**matrix;

	matrix = malloc(sizeof(int *) * n);
	row = 0;
	while (row < n)
	{
		matrix[row] = malloc(sizeof(int) * n);
		row++;
	}
	return (matrix);
}

void	ft_free_array(int *array)
{
	free(array);
}

void	ft_free_matrix(int **matrix, int n)
{
	int	row;

	row = 0;
	while (row < n)
	{
		free(matrix[row]);
		row++;
	}
	free(matrix);
}
