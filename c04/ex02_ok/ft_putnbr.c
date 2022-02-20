/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:40:57 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/17 21:24:39 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern ssize_t	write(int __fd, const void *__buf, size_t __n);

void	ft_ltoa_write(long nb)
{
	char	chr;

	if (nb < 10)
	{
		chr = nb + '0';
		write(1, &chr, 1);
	}
	else
	{
		ft_ltoa_write(nb / 10);
		chr = nb % 10 + '0';
		write(1, &chr, 1);
	}
	(void) nb;
}

void	ft_putnbr(int nb)
{
	long	work_nb;

	if (nb < 0)
	{
		write(1, "-", 1);
		work_nb = (long) nb;
		work_nb *= -1;
	}
	else
		work_nb = nb;
	ft_ltoa_write(work_nb);
}
