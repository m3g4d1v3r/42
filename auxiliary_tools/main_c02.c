/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:10:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 05:50:33 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <bsd/string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define DEST_SIZE 100
#define FT_EXIT_SUCCESS 0
#define FT_EXIT_FAILURE 1
#define EX00_FILE "ex00/ft_strcpy.c"
#define EX01_FILE "ex01/ft_strncpy.c"
#define EX02_FILE "ex02/ft_str_is_alpha.c"
#define EX03_FILE "ex03/ft_str_is_numeric.c"
#define EX04_FILE "ex04/ft_str_is_lowercase.c"
#define EX05_FILE "ex05/ft_str_is_uppercase.c"
#define EX06_FILE "ex06/ft_str_is_printable.c"
#define EX07_FILE "ex07/ft_strupcase.c"
#define EX08_FILE "ex08/ft_strlowcase.c"
#define EX09_FILE "ex09/ft_strcapitalize.c"
#define EX10_FILE "ex10/ft_strlcpy.c"
#define EX11_FILE "ex11/ft_putstr_non_printable.c"
#define EX12_FILE "ex12/ft_print_memory.c"

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int 	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if ((*str) >= '0' && (*str) <= '9')
			result = result * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	char	string_dest[DEST_SIZE];
	char	op_code;
	char	*string_src;
	char	*string_out;
	int		delim;
	
	if (argc == 1)
		return (FT_EXIT_SUCCESS);
	else if (argc == 3)
		string_src = argv[2];
	else if (argc == 4)
	{
		string_src = argv[2];
		delim = ft_atoi(argv[3]);
	}
	else
	{
		string_src = "PAMONHA";
		delim = 5;
	}
	op_code = ft_atoi(argv[1]);
	if (op_code == 0)
	{
		#include EX00_FILE
		string_out = ft_strcpy(string_dest, string_src);
		printf("src: %s\n", string_src);
		printf("dest: %s\n", string_out);
	}
	else if (op_code == 1)
	{
		#include EX01_FILE
		string_out = ft_strncpy(string_dest, string_src, delim);
		printf("src: %s\n", string_src);
		printf("dest: %s\n", string_out);
	}
	else if (op_code == 2)
	{
		#include EX02_FILE
		printf("bool: %d\n", ft_str_is_alpha(string_src));
	}
	else if (op_code == 3)
	{
		#include EX03_FILE
		printf("bool: %d\n", ft_str_is_numeric(string_src));
	}
	else if (op_code == 4)
	{
		#include EX04_FILE
		printf("bool: %d\n", ft_str_is_lowercase(string_src));
	}
	else if (op_code == 5)
	{
		#include EX05_FILE
		printf("bool: %d\n", ft_str_is_uppercase(string_src));
	}
	else if (op_code == 6)
	{
		// ./c02.out 6 "$(printf 'a\001')"
		#include EX06_FILE
		printf("bool: %d\n", ft_str_is_printable(string_src));
	}
	else if (op_code == 7)
	{
		#include EX07_FILE
		string_out = ft_strupcase(string_src);
		printf("string: %s\n", string_out);
	}
	else if (op_code == 8)
	{
		#include EX08_FILE
		string_out = ft_strlowcase(string_src);
		printf("string: %s\n", string_out);
	}
	else if (op_code == 9)
	{
		#include EX09_FILE
		char *expected_str = "Oi, Tudo Bem? 42palavras Quarenta-E-Duas; Cinquenta+E+Um";
		string_out = ft_strcapitalize(string_src);
		printf("string: %s\n", string_out);
		assert(strcmp(string_out, expected_str) == 0);
	} 
	else if (op_code == 10)
	{
		#include EX10_FILE
		char expected[DEST_SIZE];
		int expected_bool = strlcpy(expected, string_src, DEST_SIZE);
		printf("expected: %s\nexpected return: %d\n", expected, expected_bool);
		int actual_bool = ft_strlcpy(string_dest, string_src, DEST_SIZE);
		printf("actual: %s\nactual return: %d\n", string_dest, actual_bool);
		assert(strcmp(string_dest, expected) == 0);
		assert(actual_bool == expected_bool);
	}
	/*
	else if (op_code == 11)
	{
		#include EX11_FILE
		ft_putstr_non_printable(string_src);
	}
	*/
	else if (op_code == 12)
	{
		#include EX12_FILE
		string_out = ft_print_memory(string_src, delim);
		assert(string_src == string_out);
	}
	return (0);
}