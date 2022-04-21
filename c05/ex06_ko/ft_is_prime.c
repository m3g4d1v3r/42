/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:39:05 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/19 00:27:50 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_APPROX_SQRT 46340

int	ft_is_prime(int nb)
{
	int	count;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	count = 2;
	while (count <= nb / 2)
	{
		if (nb % count == 0)
			return (0);
		if (count <= FT_APPROX_SQRT)
			if (count * count == nb)
				return (0);
		count++;
	}
	return (1);
}
