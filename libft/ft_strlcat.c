/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:05 by kmin              #+#    #+#             */
/*   Updated: 2020/04/10 10:57:41 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s_len;
	size_t d_len;
	size_t i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	else
	{
		while (i < d_len)
		{
			dst++;
			i++;
		}
		while (*src++ && (size - d_len - 1) > 0)
		{
			*dst = *(src - 1);
			dst++;
			size--;
		}
		*dst = '\0';
	}
	return (s_len + d_len);
}
