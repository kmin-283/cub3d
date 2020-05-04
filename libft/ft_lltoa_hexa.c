/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:03:43 by kmin              #+#    #+#             */
/*   Updated: 2020/04/13 17:21:41 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_digit(long long n)
{
	size_t				i;
	unsigned long long	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		tmp_n = (unsigned long long)n;
	else
		tmp_n = n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 16;
	}
	return (i);
}

char			*ft_lltoa_hexa(long long n)
{
	char				*ptr;
	char				*dicimal;
	size_t				len;
	unsigned long long	temp;
	unsigned int		i;

	dicimal = "0123456789abcdef";
	len = ft_check_digit(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		temp = n < 0 ? (unsigned long long)n : (unsigned long long)n;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = dicimal[temp % 16];
			temp /= 16;
		}
	}
	return (ptr);
}
