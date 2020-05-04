/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:28:28 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:19:26 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (ptr)
	{
		ft_memmove((char *)ft_memmove(ptr, (char *)s1, s1_len) + s1_len,
		(char *)s2, s2_len);
	}
	return (ptr);
}
