/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:21:47 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 23:45:08 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_init;

	dest_init = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_init);
}
