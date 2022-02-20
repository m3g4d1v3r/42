/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:55:37 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/08 21:41:56 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFFER_SIZE 26

void	ft_print_alphabet(void)
{
	char	buffer[BUFFER_SIZE];
	int		count;
	int		stdout_fd;

	stdout_fd = 1;
	count = 0;
	while (('a' + count) <= 'z')
	{
		buffer[count] = ('a' + count);
		count++;
	}
	write(stdout_fd, buffer, count);
}
