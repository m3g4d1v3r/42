/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/14 22:00:17 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_CONTROL_LOWER 0
#define FT_CONTROL_UPPER 31
#define FT_DELETE 127

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= FT_CONTROL_LOWER && *str <= FT_CONTROL_UPPER)
			return (0);
		if (*str == FT_DELETE)
			return (0);
		str++;
	}
	return (1);
}
