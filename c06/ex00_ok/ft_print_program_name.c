/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 04:32:12 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/18 13:19:13 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*ptr;

	ptr = argv[0];
	while (*ptr)
	{
		write(1, ptr, 1);
		ptr++;
	}
	write(1, "\n", 1);
	(void) argc;
	return (0);
}
