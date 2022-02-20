/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:17:26 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/18 13:26:42 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen_2(char *str)
{
	int	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

void	ft_bubblesort(char **arg, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arg[i], arg[j]) > 0)
			{
				temp = arg[i];
				arg[i] = arg[j];
				arg[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		index;
	char	*ptr;

	index = 0;
	ft_bubblesort(&argv[1], argc - 1);
	if (argc > 1)
	{
		while (index < argc - 1)
		{
			ptr = argv[1 + index];
			while (*ptr)
			{
				write(1, ptr, 1);
				ptr++;
			}
			write(1, "\n", 1);
			index++;
		}
	}
}
