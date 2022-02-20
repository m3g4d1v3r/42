/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:54:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/15 00:07:26 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_last_ptr(char *str)
{
	while (*str++)
		;
	return (--str);
}

int	ft_is_alpha(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		return (1);
	if (*str >= 'a' && *str <= 'z')
		return (1);
	return (0);
}

int	ft_is_alphanumeric(char *str)
{
	if (ft_is_alpha(str))
		return (1);
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

void	ft_try_to_uppercase(char *str)
{
	int		offset;

	if (ft_is_alpha(str) == 1)
	{
		offset = 'a' - 'A';
		*str = *str - offset;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*head;
	char	*tail;
	int		word_state;

	head = str;
	tail = ft_get_last_ptr(str);
	word_state = 0;
	ft_try_to_uppercase(head);
	while (tail-- > head)
	{
		if (word_state == 0)
		{
			if (ft_is_alphanumeric(tail) == 1)
				word_state = 1;
		}
		else if (ft_is_alphanumeric(tail) == 0)
		{
			word_state = 0;
			if (*(tail + 1) != '\0')
				ft_try_to_uppercase(tail + 1);
		}
	}
	return (head);
}
