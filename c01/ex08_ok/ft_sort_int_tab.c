/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:35:41 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/10 04:41:31 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_3(int *a, int *b)
{
	int	swap_aux;

	swap_aux = *a;
	*a = *b;
	*b = swap_aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	while (index_1 < size)
	{
		index_2 = index_1 + 1;
		while (index_2 < size)
		{
			if (tab[index_1] > tab[index_2])
				ft_swap_3(&tab[index_1], &tab[index_2]);
			index_2++;
		}
		index_1++;
	}
}
