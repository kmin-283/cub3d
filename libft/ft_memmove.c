/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:36:07 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:16:57 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;
	size_t			i;

	s_ptr = (void *)src;
	d_ptr = dst;
	i = 0;
	if (s_ptr >= d_ptr)
	{
		while (i++ < len)
			*d_ptr++ = *s_ptr++;
	}
	else
	{
		s_ptr += len;
		d_ptr += len;
		while (i++ < len)
			*--d_ptr = *--s_ptr;
	}
	return (dst);
}
