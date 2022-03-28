/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:25:47 by msubtil-          #+#    #+#             */
/*   Updated: 2022/03/28 04:52:10 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUFFSIZE 4096
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void	ft_putstr_dspf(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_display_file(char *file_str)
{
	int		fd;
	int		read_res;
	char	buffer[BUFFSIZE];

	fd = open(file_str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	read_res = read(fd, buffer, BUFFSIZE);
	while (read_res > 0)
	{
		write(1, buffer, read_res);
		read_res = read(fd, buffer, BUFFSIZE);
	}
	if (close(fd) < 0 || read_res < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		ft_putstr_dspf("File name missing.");
		return (EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_putstr_dspf("Too many arguments.");
		return (EXIT_FAILURE);
	}
	return (ft_display_file(argv[1]));
}
