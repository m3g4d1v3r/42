/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:18:07 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/13 10:33:26 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_valid_digit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

char	*ft_reverse_str(char *str, int size)
{
	int		index;
	char	aux;

	index = 0;
	while (index < size / 2)
	{
		aux = str[index];
		str[index] = str[size - index - 1];
		str[size - index - 1] = aux;
		index++;
	}
	return (str);
}

int	ft_atoi_whitespace(char *str)
{
	int	result;

	result = 0;
	while (*str != ' ' && *str != '\0')
	{
		if (ft_is_valid_digit(*str))
			result = result * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (result);
}

int	ft_itoa(char *str, int value)
{
	int	index;

	index = 0;
	if (value == 0)
	{
		str[index] = '0';
		str[index + 1] = '\0';
		return (1);
	}
	while (value != 0)
	{
		str[index] = value % 10 + '0';
		value /= 10;
		index++;
	}
	ft_reverse_str(str, index);
	return (index);
}
