/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 02:17:01 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 20:47:15 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFFER_SIZE 10

void	ft_print_numbers(void)
{
	char	buffer[BUFFER_SIZE];
	int		count;
	int		stdout_fd;

	stdout_fd = 1;
	count = 0;
	while (('0' + count) <= '9')
	{
		buffer[count] = ('0' + count);
		count++;
	}
	write(stdout_fd, buffer, count);
}
