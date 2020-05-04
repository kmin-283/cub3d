/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:00:25 by kmin              #+#    #+#             */
/*   Updated: 2020/04/13 17:20:56 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_digit(unsigned int n)
{
	size_t			i;
	unsigned	int	tmp_n;

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

char			*ft_itoa_u(unsigned int n)
{
	char			*ptr;
	char			*dicimal;
	size_t			len;
	unsigned	int temp;
	unsigned	int	i;

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
