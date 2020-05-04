/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:46:24 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:23:47 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_arr(char const *s, char c)
{
	int		flag;
	size_t	count;

	if (!s)
		return (0);
	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s == c && flag)
			flag = 0;
		else if (*s != c && !flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_c_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char		*ft_free(char **ptr, size_t i)
{
	int j;

	j = (int)i;
	while (j >= 0)
	{
		free(ptr[j]);
		ptr[j] = NULL;
		j--;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char		*ft_fill_arr(char const *s, char **ptr, size_t i, size_t len)
{
	char *tmp_ptr;

	tmp_ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (tmp_ptr)
	{
		ft_memmove(tmp_ptr, s, len);
		tmp_ptr[len] = '\0';
	}
	else
	{
		tmp_ptr = ft_free(ptr, i);
	}
	return (tmp_ptr);
}

char			**ft_split(char const *s, char c)
{
	size_t	num_of_arr;
	char	**ptr;
	size_t	len;
	size_t	i;

	num_of_arr = ft_count_arr(s, c);
	ptr = (char **)ft_calloc(num_of_arr + 1, sizeof(char *));
	i = 0;
	if (ptr)
	{
		while (*s && num_of_arr--)
		{
			while (*s == c && *s)
				s++;
			len = ft_c_strlen(s, c);
			ptr[i] = ft_fill_arr(s, ptr, i, len);
			if (ptr[i] == NULL)
				return (NULL);
			s += len;
			i++;
		}
		ptr[i] = NULL;
	}
	return (ptr);
}
