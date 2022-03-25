/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:19:05 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/25 21:23:35 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar4(char chr)
{
	write(1, &chr, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar4(*str++);
}
