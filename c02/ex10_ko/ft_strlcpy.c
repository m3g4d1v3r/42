/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/15 13:22:31 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;

	if (size < 1)
		return (0);
	counter = 0;
	while (--size && *src)
	{
		*dest++ = *src++;
		counter++;
	}
	*dest = '\0';
	while (*src++)
		counter++;
	return (counter);
}
