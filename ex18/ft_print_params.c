/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:41:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/25 21:46:41 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar5(char chr)
{
	write(1, &chr, 1);
}

void	ft_putstr2(char *str)
{
	while (*str)
	{
		ft_putchar5(*str);
		str++;
	}
	ft_putchar5('\n');
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr2(argv[i]);
		i++;
	}
}
