/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:01:17 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:17:51 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t size)
{
	unsigned int	s_len;
	size_t			i;

	s_len = ft_strlen(src);
	i = 0;
	while (i < size - 1 && (int)size - 1 > 0 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (size)
		*dst = '\0';
	return (s_len);
}
