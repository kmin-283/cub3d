/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:52:08 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:11:21 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			j;
	unsigned int	flag;

	ptr = (void *)b;
	flag = 1;
	i = 0;
	while (i < len && flag)
	{
		if (*ptr == (unsigned char)c)
		{
			j = i;
			flag = 0;
		}
		ptr++;
		i++;
	}
	if (!flag)
		return ((void *)b + j);
	else
		return (NULL);
}
