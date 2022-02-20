/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation_eng.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:59:51 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 03:28:48 by msubtil-         ###   ########.fr       */
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

int		ft_get_init_matrix_value(struct s_data *in);
int		ft_get_work_matrix_value(struct s_data *in);
void	ft_print_array(int *array, int n);
void	ft_print_matrix(int **matrix, int n);
int		ft_validate_matrix(int **matrix, int **observers, int n);
void	ft_init_stack(struct s_data *in, int n);
void	ft_free_stack(struct s_data *in);
void	ft_push_stack(struct s_data *in, int value);
int		ft_pop_stack(struct s_data *in);
int		ft_sudoku_available(struct s_data *in, int value);
void	ft_copy_matrix(int **dest, int **src, int n);
int		ft_depth_search(struct s_data *in, int n, int element);

int	ft_depth_search_base_case(struct s_data *in)
{
	if (ft_validate_matrix(in->matrix, in->observers, in->n) == 1)
	{
		ft_print_matrix(in->matrix, in->n);
		return (1);
	}
	return (0);
}

int	ft_depth_search_iterator(struct s_data *in, int n, int element)
{
	int	offset;
	int	next_element;

	offset = 1;
	while (offset <= n)
	{
		next_element = (element + offset) % n;
		if (ft_depth_search(in, n, next_element) == 1)
			return (1);
		offset++;
	}
	return (0);
}

int	ft_depth_search(struct s_data *in, int n, int element)
{
	int	next_element;
	int	result;

	result = 0;
	if (in->index == in->size)
		return (ft_depth_search_base_case(in));
	else if (ft_sudoku_available(in, element + 1) == 0)
		return (0);
	ft_push_stack(in, element + 1);
	if (in->index == in->size)
	{
		result = ft_depth_search(in, n, -1);
		ft_pop_stack(in);
		return (result);
	}
	else if (ft_get_init_matrix_value(in) != 0)
	{
		next_element = ft_get_init_matrix_value(in) - 1;
		if (ft_depth_search(in, n, next_element) == 1)
			return (1);
	}
	else
		result = ft_depth_search_iterator(in, n, element);
	ft_pop_stack(in);
	return (result);
}

int	ft_permutation_engine(int **init, int **work, int **observers, int n)
{
	struct s_data	eng_stack;
	int				offset;
	int				result;

	ft_init_stack(&eng_stack, n);
	eng_stack.init = init;
	eng_stack.matrix = work;
	eng_stack.observers = observers;
	result = 0;
	offset = 0;
	while (offset < n)
	{
		result = ft_depth_search(&eng_stack, n, offset);
		if (result == 1)
		{
			break ;
		}
		offset++;
	}
	ft_free_stack(&eng_stack);
	return (result);
}
