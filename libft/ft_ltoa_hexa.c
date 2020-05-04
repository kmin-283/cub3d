/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:15:00 by kmin              #+#    #+#             */
/*   Updated: 2020/04/13 17:20:27 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_digit(long long n)
{
	size_t			i;
	unsigned long	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		tmp_n = (unsigned long)n;
	else
		tmp_n = (unsigned long)n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 16;
	}
	return (i);
}

char			*ft_ltoa_hexa(long long n)
{
	char			*ptr;
	char			*dicimal;
	size_t			len;
	unsigned long	temp;
	unsigned int	i;

	dicimal = "0123456789abcdef";
	len = ft_check_digit(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		temp = n < 0 ? (unsigned long)n : (unsigned long)n;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = dicimal[temp % 16];
			temp /= 16;
		}
	}
	return (ptr);
}
