/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 05:18:16 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*init;
	int		offset;

	init = str;
	offset = 'a' - 'A';
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + offset;
		str++;
	}
	return (init);
}
