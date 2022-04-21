/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:11:05 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 05:03:49 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	int	file_descriptor;
	int	char_size;

	file_descriptor = 1;
	char_size = 1;
	write(file_descriptor, &c, char_size);
	return ;
}
