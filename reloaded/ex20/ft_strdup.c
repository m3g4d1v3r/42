/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:03:13 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/29 19:36:21 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		str_size;

	str_size = ft_strlen2(src);
	new_str = (char *) malloc(sizeof(char) * str_size);
	while (*src)
		*new_str++ = *src++;
	*new_str = '\0';
	return (new_str - str_size);
}
