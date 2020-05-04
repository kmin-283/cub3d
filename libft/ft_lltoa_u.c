/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:36:25 by kmin              #+#    #+#             */
/*   Updated: 2020/04/13 17:20:12 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_digit(unsigned long long n)
{
	size_t				i;
	unsigned long long	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	tmp_n = n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 10;
	}
	return (i);
}

char			*ft_lltoa_u(unsigned long long n)
{
	char				*ptr;
	char				*dicimal;
	size_t				len;
	unsigned long long	temp;
	unsigned int		i;

	dicimal = "0123456789";
	len = ft_check_digit(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		temp = n;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = dicimal[temp % 10];
			temp /= 10;
		}
	}
	return (ptr);
}
