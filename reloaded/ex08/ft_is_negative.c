/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:44:33 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/24 03:53:57 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar3(char chr)
{
	write(1, &chr, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar3('P');
	else
		ft_putchar3('N');
}
