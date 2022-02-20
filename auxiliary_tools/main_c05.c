/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:10:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/19 05:55:05 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FT_NULL_TEST (void *) 0
#define DEST_SIZE 100
#define FT_EXIT_SUCCESS 0
#define FT_EXIT_FAILURE 1
#define EX00_FILE "ex00/ft_iterative_factorial.c"
#define EX01_FILE "ex01/ft_recursive_factorial.c"
#define EX02_FILE "ex02/ft_iterative_power.c"
#define EX03_FILE "ex03/ft_recursive_power.c"
#define EX04_FILE "ex04/ft_fibonacci.c"
#define EX05_FILE "ex05/ft_sqrt.c"
#define EX06_FILE "ex06/ft_is_prime.c"
#define EX07_FILE "ex07/ft_find_next_prime.c"
#define EX08_FILE "ex08/ft_ten_queens_puzzle.c"

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int	main(int argc, char *argv[])
{
	char	op_code;

	if (argc == 1)
		return (FT_EXIT_FAILURE);
	else if (argc != 2)
		return (FT_EXIT_FAILURE);
	op_code = atoi(argv[1]);
	if (op_code == 0)
	{
		#include EX00_FILE
		assert(ft_iterative_factorial(12) == 479001600);
		assert(ft_iterative_factorial(0) == 0);
		assert(ft_iterative_factorial(-99) == 0);
	}
	else if (op_code == 1)
	{
		#include EX01_FILE
		assert(ft_recursive_factorial(12) == 479001600);
		assert(ft_recursive_factorial(0) == 0);
		assert(ft_recursive_factorial(-99) == 0);
	}
	else if (op_code == 2)
	{
		#include EX02_FILE
		assert(ft_iterative_power(2, 30) == 1073741824);
		assert(ft_iterative_power(2, -1) == 0);
		assert(ft_iterative_power(2, 0) == 1);
		assert(ft_iterative_power(0, 0) == 1);
	}
	else if (op_code == 3)
	{
		#include EX03_FILE
		assert(ft_recursive_power(2, 30) == 1073741824);
		assert(ft_recursive_power(2, -1) == 0);
		assert(ft_recursive_power(2, 0) == 1);
		assert(ft_recursive_power(0, 0) == 1);
	}
	else if (op_code == 4)
	{
		#include EX04_FILE
		assert(ft_fibonacci(0) == 0);
		assert(ft_fibonacci(1) == 1);
		assert(ft_fibonacci(2) == 1);
		assert(ft_fibonacci(3) == 2);
		assert(ft_fibonacci(4) == 3);
		assert(ft_fibonacci(5) == 5);
		assert(ft_fibonacci(6) == 8);
		assert(ft_fibonacci(7) == 13);
		assert(ft_fibonacci(8) == 21);
		assert(ft_fibonacci(9) == 34);
		assert(ft_fibonacci(10) == 55);
		assert(ft_fibonacci(-1) == -1);
		assert(ft_fibonacci(45) == 1134903170);
	}
	else if (op_code == 5)
	{
		#include EX05_FILE
		assert(ft_sqrt(-1) == 0);
		assert(ft_sqrt(0) == 0);
		assert(ft_sqrt(1) == 0);
		assert(ft_sqrt(2) == 0);
		assert(ft_sqrt(3) == 0);
		assert(ft_sqrt(4) == 2);
		assert(ft_sqrt(9) == 3);
		assert(ft_sqrt(16) == 4);
		assert(ft_sqrt(25) == 5);
		assert(ft_sqrt(2147395600) == 46340);
	}
	else if (op_code == 6)
	{
		#include EX06_FILE
		assert(ft_is_prime(-2147483648) == 0);
		assert(ft_is_prime(-1) == 0);
		assert(ft_is_prime(0) == 0);
		assert(ft_is_prime(1) == 1);
		assert(ft_is_prime(2) == 1);
		assert(ft_is_prime(3) == 1);
		assert(ft_is_prime(4) == 0);
		assert(ft_is_prime(5) == 1);
		assert(ft_is_prime(2147483647) == 1);
		assert(ft_is_prime(2147483646) == 0);
	}
	else if (op_code == 7)
	{
		#include EX07_FILE
		assert(ft_find_next_prime(-2147483648) == 1);
		assert(ft_find_next_prime(1) == 1);
		assert(ft_find_next_prime(2) == 2);
		assert(ft_find_next_prime(3) == 3);
		assert(ft_find_next_prime(4) == 5);
		assert(ft_find_next_prime(5) == 5);
		assert(ft_find_next_prime(907) == 907);
		assert(ft_find_next_prime(908) == 911);
		assert(ft_find_next_prime(2147479259) == 2147479259);
		assert(ft_find_next_prime(2147479260) == 2147479273);
		assert(ft_find_next_prime(2147483647) == 2147483647);
	}
	else if (op_code == 7)
	{
		#include EX07_FILE
		assert(ft_find_next_prime(-2147483648) == 1);
		assert(ft_find_next_prime(1) == 1);
		assert(ft_find_next_prime(2) == 2);
		assert(ft_find_next_prime(3) == 3);
		assert(ft_find_next_prime(4) == 5);
		assert(ft_find_next_prime(5) == 5);
		assert(ft_find_next_prime(907) == 907);
		assert(ft_find_next_prime(908) == 911);
		assert(ft_find_next_prime(2147479259) == 2147479259);
		assert(ft_find_next_prime(2147479260) == 2147479273);
		assert(ft_find_next_prime(2147483647) == 2147483647);
	}
	else if (op_code == 8)
	{
		#include EX08_FILE
		assert(ft_ten_queens_puzzle() == 724);
	}
	return (FT_EXIT_SUCCESS);
}
