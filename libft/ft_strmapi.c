/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:31:07 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:18:18 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned	int	i;
	size_t			len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
