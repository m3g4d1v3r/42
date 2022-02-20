/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:26:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 03:26:36 by msubtil-         ###   ########.fr       */
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

void	ft_init_stack(struct s_data *in, int n)
{
	in->array = malloc(sizeof(int) * n * n);
	in->index = 0;
	in->size = n * n;
	in->n = n;
}

void	ft_free_stack(struct s_data *in)
{
	free(in->array);
}

void	ft_push_stack(struct s_data *in, int value)
{
	int	i;
	int	j;

	if (in->index < in->size)
	{
		in->array[in->index] = value;
		i = in->index / in->n;
		j = in->index % in->n;
		in->matrix[i][j] = value;
		in->index++;
	}
}

int	ft_pop_stack(struct s_data *in)
{
	int	aux;
	int	i;
	int	j;

	if (in->index > 0)
	{
		in->index--;
		aux = in->array[in->index];
		in->array[in->index] = 0;
		i = in->index / in->n;
		j = in->index % in->n;
		in->matrix[i][j] = 0;
		return (aux);
	}
	return (-1);
}
