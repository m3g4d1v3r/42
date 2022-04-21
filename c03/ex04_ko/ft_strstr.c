/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:35:07 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 23:49:46 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_NULL ((void *)0)

int	ft_inner_word_search(char *hays_inner, char *need_inner)
{
	int	found_it;

	found_it = 1;
	while (*hays_inner && *need_inner)
	{
		if (*hays_inner != *need_inner)
		{
			found_it = 0;
			break ;
		}
		hays_inner++;
		need_inner++;
	}
	return (found_it);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*str == '\0')
		return (FT_NULL);
	while (*str)
	{
		if (*str == *to_find)
		{
			if (ft_inner_word_search(str, to_find) == 1)
				return (str);
		}
		str++;
	}
	return (FT_NULL);
}
