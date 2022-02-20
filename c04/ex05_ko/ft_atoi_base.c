/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:42:17 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/18 04:13:29 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASCII_VALUES 256

int	ft_validate_base_2(char *base)
{
	char	ascii_table[ASCII_VALUES];
	int		index;

	index = 0;
	if (base[0] == '\0')
		return (0);
	while (index < ASCII_VALUES)
		ascii_table[index++] = 0;
	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		if (base[index] == ' ')
			return (0);
		if (ascii_table[(int) base[index]] >= 1)
			return (0);
		else
			ascii_table[(int) base[index]] += 1;
		index++;
	}
	return (index);
}

int	ft_get_quantity(char *base, char element)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == element)
			return (index);
		index++;
	}
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	range;
	int	factor;

	range = ft_validate_base_2(base);
	if (range == 0)
		return (0);
	factor = 1;
	if (*str == '-')
	{
		factor = -1;
		str++;
	}
	res = 0;
	while (*str)
	{
		res = res * range + ft_get_quantity(base, *str);
		str++;
	}
	return (res * factor);
}
