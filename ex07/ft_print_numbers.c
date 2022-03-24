/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:44:33 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/24 03:51:35 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char chr)
{
	write(1, &chr, 1);
}

void	ft_print_numbers(void)
{
	int	nb;

	nb = 0;
	while (nb <= 9)
	{
		ft_putchar2('0' + nb);
		nb++;
	}
}
