/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:07:06 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:14:12 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;
	size_t			i;
	unsigned int	flag;

	s_ptr = (void *)src;
	d_ptr = dst;
	i = 0;
	flag = 1;
	while (i < len && flag)
	{
		if (*s_ptr == c)
			flag = 0;
		*d_ptr = *s_ptr;
		d_ptr++;
		s_ptr++;
		i++;
	}
	if (!flag)
		return (dst + i);
	else
		return (NULL);
}
