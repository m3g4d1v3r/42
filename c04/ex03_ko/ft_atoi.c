/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:26:47 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/17 21:51:25 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	factor;
	int	init;

	res = 0;
	factor = 1;
	init = 1;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == '-' && init)
			factor *= -1;
		else if (*str == '+' && init)
			;
		else if (*str >= '0' && *str <= '9')
		{
			res = res * 10 + *str - '0';
			init = 0;
		}
		else
			break ;
		str++;
	}
	return (res * factor);
}
