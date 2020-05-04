/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:23:28 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:18:51 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	i = 0;
	d_ptr = dst;
	s_ptr = (void *)src;
	while (i < len)
	{
		*d_ptr = *s_ptr;
		d_ptr++;
		s_ptr++;
		i++;
	}
	return (dst);
}
