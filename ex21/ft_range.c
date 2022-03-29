/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:18:13 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/29 19:40:21 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define FT_NULL 0x0

int	*ft_range(int min, int max)
{
	unsigned int	u_i;
	unsigned int	u_max;
	int				*new_arr;

	if (min >= max)
		return (0x0);
	else if (min < 0)
		u_max = -1 * min + max;
	else
		u_max = min + max;
	new_arr = (int *) malloc(sizeof(int) * (u_max));
	u_i = 0;
	while (u_i < u_max)
	{
		new_arr[u_i] = min + u_i;
		u_i++;
	}
	return (new_arr);
}
