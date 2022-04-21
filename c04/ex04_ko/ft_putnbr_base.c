/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:53:29 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/18 04:12:55 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern ssize_t	write(int __fd, const void *__buf, size_t __n);

int	ft_validate_base(char *base)
{
	int	index;

	index = 0;
	if (base[index] == '\0')
		return (0);
	if (base[index + 1] == '\0')
		return (0);
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		index++;
	}
	return (index);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char		buffer[100];
	long		nbr_2;
	int			index;
	int			range;

	nbr_2 = (long) nbr;
	index = 0;
	range = ft_validate_base(base);
	if (range == 0)
		return ;
	if (nbr_2 < 0)
	{
		nbr_2 *= -1;
		write(1, "-", 1);
	}
	while (nbr_2 > 0)
	{
		buffer[index++] = base[nbr_2 % range];
		nbr_2 /= range;
	}
	while (index--)
		write(1, &buffer[index], 1);
}
