/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:30:38 by kmin              #+#    #+#             */
/*   Updated: 2020/05/22 21:40:04 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen_gnl(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset_gnl(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = dest;
	while (i < len)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (dest);
}

void	*ft_calloc_gnl(size_t number, size_t size)
{
	void *ptr;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	ptr = malloc(size * number);
	if (ptr)
		ft_memset_gnl(ptr, 0, number * size);
	return (ptr);
}

char	*ft_tr_strdup(const char *str, char *newline)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	point;

	if (!str)
		return (NULL);
	len = ft_strlen_gnl(str);
	ptr = (char *)ft_calloc_gnl(len + 1, sizeof(char));
	if (ptr && !newline)
		ft_memmove_gnl(ptr, str, len + 1);
	else if (ptr && newline)
	{
		point = (newline - str) > 0 ? newline - str : 0;
		ft_memmove_gnl(ptr, str, point);
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (ft_tr_strdup(s1, NULL));
	else if (!s1)
		return (ft_tr_strdup(s2, NULL));
	else if (!s2)
		return (ft_tr_strdup(s1, NULL));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	ptr = (char *)ft_calloc_gnl(s1_len + s2_len + 1, sizeof(char));
	if (ptr)
	{
		ft_memmove_gnl((char *)ft_memmove_gnl(ptr, (char *)s1, s1_len) + s1_len,
				(char *)s2, s2_len);
	}
	return (ptr);
}
