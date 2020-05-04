/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:12:47 by kmin              #+#    #+#             */
/*   Updated: 2020/04/13 17:22:19 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_digit(int n)
{
	size_t			i;
	unsigned	int	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		tmp_n = (unsigned int)n;
	else
		tmp_n = n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 16;
	}
	return (i);
}

char			*ft_itoa_hexa_upper(int n)
{
	char			*ptr;
	char			*dicimal;
	size_t			len;
	unsigned	int temp;
	unsigned	int	i;

	dicimal = "0123456789ABCDEF";
	len = ft_check_digit(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		temp = n < 0 ? (unsigned int)n : (unsigned int)n;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = dicimal[temp % 16];
			temp /= 16;
		}
	}
	return (ptr);
}
