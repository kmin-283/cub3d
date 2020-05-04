/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:10:21 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:20:33 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	size_t	len;
	int		find;

	i = 0;
	j = 0;
	find = 0;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == (char)c)
		{
			j = i;
			find = 1;
		}
		i++;
	}
	if (j == 0 && !find)
		return (NULL);
	else
		return ((char *)(s + j));
}
