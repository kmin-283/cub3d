/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:52:37 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:22:23 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	int				i_len;

	if (!s)
		return ((char *)s);
	i_len = (int)len;
	ptr = (char *)ft_calloc(i_len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		if ((unsigned int)ft_strlen(s) > start)
		{
			while (i_len-- > 0 && s[start])
			{
				ptr[i] = s[start];
				start++;
				i++;
			}
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
