/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:07:05 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/19 00:27:57 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INT_MAX 2147483647
#define FT_APPROX_SQRT 46340

int	ft_is_prime_2(int nb)
{
	int	count;

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

int	ft_find_next_prime(int nb)
{
	int	aux;

	if (nb <= 1)
		return (1);
	aux = nb;
	while (aux < FT_INT_MAX)
	{
		if (ft_is_prime_2(aux) == 1)
			return (aux);
		aux++;
	}
	return (FT_INT_MAX);
}
