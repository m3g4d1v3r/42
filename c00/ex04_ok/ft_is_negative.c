/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 02:17:01 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/06 02:23:19 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int		stdout_fd;

	stdout_fd = 1;
	if (n >= 0)
		write(stdout_fd, "P", 1);
	else
		write(stdout_fd, "N", 1);
}
