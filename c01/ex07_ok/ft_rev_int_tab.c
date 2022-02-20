/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:26:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/10 04:41:29 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_2(int *a, int *b)
{
	int	swap_aux;

	swap_aux = *a;
	*a = *b;
	*b = swap_aux;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;

	counter = 0;
	while (counter < size / 2)
	{
		ft_swap_2(&tab[counter], &tab[size - counter - 1]);
		counter++;
	}
}
