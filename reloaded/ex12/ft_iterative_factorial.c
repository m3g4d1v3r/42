/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 04:11:25 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/25 16:39:33 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	factorial = 1;
	while (nb > 0)
		factorial *= nb--;
	return (factorial);
}
