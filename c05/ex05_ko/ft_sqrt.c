/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:28:23 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/19 00:27:45 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_APPROX_SQRT 46340

int	ft_sqrt(int nb)
{
	int	count;

	if (nb < 0)
		return (0);
	count = 0;
	while (count <= nb / 2)
	{
		if (count <= FT_APPROX_SQRT)
		{
			if (count * count == nb)
				return (count);
		}
		else
			return (0);
		count++;
	}
	return (0);
}
