/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:35:42 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 02:49:29 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define OBSERVER_LINES 4

int	ft_is_valid_digit(char chr);
int	ft_atoi_whitespace(char *str);

int	ft_get_input_size(char *big_str)
{
	char	*ptr_nb;
	int		is_nb;
	int		counter_nb;

	is_nb = 0;
	counter_nb = 0;
	while (*big_str)
	{
		if (is_nb == 1 && ft_is_valid_digit(*big_str) == 0)
		{
			counter_nb++;
			is_nb = 0;
		}
		else if (is_nb == 0 && ft_is_valid_digit(*big_str) == 1)
		{
			ptr_nb = big_str;
			is_nb = 1;
		}
		big_str++;
	}
	if (ptr_nb != big_str && ft_is_valid_digit(*(big_str - 1)) == 1)
		counter_nb++;
	return (counter_nb);
}

void	ft_parse_input(char *big_str, int *input_array)
{
	char	*ptr_nb;
	int		is_nb;
	int		counter_nb;

	is_nb = 0;
	counter_nb = 0;
	while (*big_str)
	{
		if (is_nb == 1 && ft_is_valid_digit(*big_str) == 0)
		{
			input_array[counter_nb++] = ft_atoi_whitespace(ptr_nb);
			is_nb = 0;
		}
		else if (is_nb == 0 && ft_is_valid_digit(*big_str) == 1)
		{
			ptr_nb = big_str;
			is_nb = 1;
		}
		big_str++;
	}
	if (ptr_nb != big_str && ft_is_valid_digit(*(big_str - 1)) == 1)
		input_array[counter_nb++] = ft_atoi_whitespace(ptr_nb);
}

int	ft_validate_input_str(char *big_str)
{
	while (*big_str)
	{
		if (ft_is_valid_digit(*big_str) == 0)
			if ((*big_str == ' ') == 0)
				if ((*big_str == '\t') == 0)
					return (0);
		big_str++;
	}
	return (1);
}

int	ft_validate_input_array(int *array, int size, int n)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (array[index++] > n)
			return (0);
	}
	return (1);
}

int	ft_validate_input_size(int size)
{
	return (size % OBSERVER_LINES == 0);
}
