/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 04:44:01 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_CONTROL_LOWER 0
#define FT_CONTROL_UPPER 31
#define FT_DELETE 127
#define FT_ADDRESS_SIZE 15
#define FT_CHUNK 2
#define FT_MEM_INCREMENT 16
#define FT_BASE_MAX 0x100000000000000

void	ft_hexify_value(long long value)
{
	char	hex_buffer[2];
	char	aux;
	int		iterator;

	hex_buffer[0] = value / 0x10;
	hex_buffer[1] = value % 0x10;
	iterator = 0;
	while (iterator < 2)
	{
		aux = hex_buffer[iterator];
		if (aux >= 10 && aux <= 15)
			aux = aux - 10 + 'a';
		else if (aux < 10)
			aux = aux + '0';
		hex_buffer[iterator] = aux;
		iterator++;
	}
	write(1, hex_buffer, 2);
}

void	ft_header_part(void *start)
{
	unsigned long long	addr_value;
	unsigned long long	divisor;
	char				tail;

	addr_value = (unsigned long long) start;
	divisor = FT_BASE_MAX;
	while (divisor > addr_value)
	{
		divisor /= 0x10;
		if (divisor > addr_value)
			write(1, "0", 1);
	}
	while (divisor != 0)
	{
		ft_hexify_value(addr_value / divisor);
		addr_value %= divisor;
		divisor /= 0x100;
	}
	tail = addr_value;
	if (tail >= 10 && tail <= 15)
		tail = tail - 10 + 'a';
	else if (tail < 10)
		tail = tail + '0';
	write(1, &tail, 1);
}

void	ft_middle_part(void *start, int bytes)
{
	int		offset;
	char	*mem_data;

	offset = 0;
	while (offset < bytes)
	{
		mem_data = start + offset;
		ft_hexify_value(*mem_data);
		if (offset % 2 != 0)
			write(1, " ", 1);
		offset++;
	}
}

void	ft_tail_part(void *start, int bytes)
{
	int		offset;
	char	*mem_data;

	offset = 0;
	while (offset < bytes)
	{
		mem_data = start + offset;
		if (*mem_data >= FT_CONTROL_LOWER && *mem_data <= FT_CONTROL_UPPER)
			write(1, ".", 1);
		else if (*mem_data == FT_DELETE)
			write(1, ".", 1);
		else
			write(1, mem_data, 1);
		offset++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*start;
	int		line_bytes;

	start = addr;
	while (size)
	{
		if (size >= FT_MEM_INCREMENT)
			line_bytes = FT_MEM_INCREMENT;
		else
			line_bytes = size;
		ft_header_part(addr);
		write(1, ": ", 2);
		ft_middle_part(addr, line_bytes);
		if (line_bytes != FT_MEM_INCREMENT)
			write(1, "     ", 5);
		else
			write(1, " ", 1);
		ft_tail_part(addr, line_bytes);
		write(1, "\n", 1);
		addr += FT_MEM_INCREMENT;
		size -= line_bytes;
	}
	return (start);
}
