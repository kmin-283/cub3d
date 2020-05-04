/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:19:07 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:24:30 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_string(const char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	if ((len = ft_strlen(s1)) == 0)
		return ((char *)s1);
	i = 0;
	j = 0;
	start = 0;
	while (ft_is_string(s1[start], (char *)set))
		start++;
	while (s1[start + i])
		i++;
	while (ft_is_string(s1[start + i - j - 1], (char *)set) && i - j > 0)
		j++;
	ptr = ft_substr(s1, start, i - j);
	return (ptr);
}
