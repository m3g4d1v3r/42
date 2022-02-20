/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:51:55 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/17 01:16:49 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		n;
	char	*ptr;

	n = size;
	ptr = src;
	while (*ptr && --n)
	{
		*dest++ = *ptr++;
	}
	if (n == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*ptr++)
			;
	}
	return (ptr - src - 1);
}
