/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:47 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_CONTROL_LOWER 0
#define FT_CONTROL_UPPER 31
#define FT_DELETE 127

int	ft_chr_is_printable(char str)
{
	if (str >= FT_CONTROL_LOWER && str <= FT_CONTROL_UPPER)
		return (0);
	if (str == FT_DELETE)
		return (0);
	return (1);
}

void	ft_convert_to_hex(char *hex, char chr)
{
	hex[1] = chr / 16;
	hex[2] = chr % 16;
	if (hex[1] >= 10)
		hex[1] = hex[1] - 10 + 'a';
	else
		hex[1] = hex[1] + '0';
	if (hex[2] >= 10)
		hex[2] = hex[2] - 10 + 'a';
	else
		hex[2] = hex[2] + '0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[3];

	hex[0] = '\\';
	while (*str)
	{
		if (!ft_chr_is_printable(*str))
		{
			ft_convert_to_hex(hex, *str);
			write(1, hex, 3);
		}
		else
			write(1, str, 1);
		str++;
	}
}
