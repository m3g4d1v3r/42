/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:52:33 by msubtil-          #+#    #+#             */
/*   Updated: 2022/02/16 21:20:32 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	while (n)
	{
		if (*ptr1 != *ptr2)
			break ;
		if (*ptr1 == '\0')
			break ;
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
	{
		ptr1--;
		ptr2--;
	}
	return (*ptr1 - *ptr2);
}
