/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:18:02 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 03:27:58 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_EXIT_SUCCESS 0
#define FT_EXIT_FAILURE 1
#define FT_OBSERVER_LINES 4
#define FT_COL_UP 0
#define FT_COL_DOWN 1
#define FT_ROW_LEFT 2
#define FT_ROW_RIGHT 3

int		ft_get_input_size(char *big_str);
void	ft_parse_input(char *big_str, int *input_array);
int		ft_validate_input_size(int size);
void	ft_fill_naive(int **matrix, int **observers, int n);
int		ft_permutation_engine(int **init, int **work, int **observers, int n);
int		*ft_allocate_array(int n_elements);
int		**ft_allocate_matrix(int n);
void	ft_free_array(int *array);
void	ft_free_matrix(int **matrix, int n);
void	ft_print_array(int *array, int n);
void	ft_print_matrix(int **matrix, int n);
void	ft_copy_matrix(int **dest, int **src, int n);
int		ft_validate_input_str(char *big_str);
int		ft_validate_input_array(int *array, int size, int n);

void	ft_print_error(void)
{
	write(1, "Error", sizeof(char) * 5);
	write(1, "\n", 1);
}

void	ft_fill_array(int *observers, int *input_array, int offset, int n)
{
	int	index;

	index = offset;
	while (index < (offset + n))
	{
		observers[index - offset] = input_array[index];
		index++;
	}
}

int	ft_initialize_process(int *input, int **init, int **work, int n)
{
	int	index;
	int	offset;
	int	*observers[FT_OBSERVER_LINES];
	int	result;

	index = 0;
	offset = 0;
	while (index < FT_OBSERVER_LINES)
	{
		observers[index] = ft_allocate_array(n);
		ft_fill_array(observers[index], input, offset, n);
		offset += n;
		index++;
	}
	ft_fill_naive(init, observers, n);
	result = ft_permutation_engine(init, work, observers, n);
	index = 0;
	while (index < FT_OBSERVER_LINES)
		ft_free_array(observers[index++]);
	return (result);
}

int	ft_allocation_step(char *input, int input_size)
{
	int	*input_array;
	int	**init_matrix;
	int	**work_matrix;
	int	n;
	int	result;

	input_array = ft_allocate_array(input_size);
	if (ft_validate_input_size(input_size) == 0)
		return (0);
	ft_parse_input(input, input_array);
	n = input_size / FT_OBSERVER_LINES;
	if (ft_validate_input_array(input_array, input_size, n) == 0)
		return (0);
	init_matrix = ft_allocate_matrix(n);
	work_matrix = ft_allocate_matrix(n);
	result = ft_initialize_process(input_array, init_matrix, work_matrix, n);
	ft_free_matrix(work_matrix, n);
	ft_free_matrix(init_matrix, n);
	ft_free_array(input_array);
	return (result);
}

int	main(int argc, char *argv[])
{
	int	input_size;

	if (argc == 2)
	{
		input_size = ft_get_input_size(argv[1]);
		if (ft_validate_input_str(argv[1]) == 0)
		{
			ft_print_error();
			return (FT_EXIT_FAILURE);
		}
		if (ft_allocation_step(argv[1], input_size) == 0)
		{
			ft_print_error();
			return (FT_EXIT_FAILURE);
		}
	}
	else
	{
		ft_print_error();
		return (FT_EXIT_FAILURE);
	}
	return (FT_EXIT_SUCCESS);
}

