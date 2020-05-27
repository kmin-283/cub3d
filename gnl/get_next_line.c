/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:09:43 by kmin              #+#    #+#             */
/*   Updated: 2020/05/22 21:33:53 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_tr_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

void	*ft_memmove_gnl(void *dst, const void *src, size_t len)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;
	size_t			i;

	s_ptr = (void *)src;
	d_ptr = dst;
	i = 0;
	if (s_ptr >= d_ptr)
	{
		while (i++ < len)
			*d_ptr++ = *s_ptr++;
	}
	else
	{
		s_ptr += len;
		d_ptr += len;
		while (i++ < len)
			*--d_ptr = *--s_ptr;
	}
	return (dst);
}

char	*ft_line_content(char *newline, char **line, char **ptr_fd)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	if (*ptr_fd)
		tmp = ft_tr_strdup(*ptr_fd, newline);
	else
		tmp = ft_tr_strdup("", newline);
	if (newline)
	{
		i = (newline - *ptr_fd) + 1;
		len = ft_strlen_gnl(*ptr_fd);
		ft_memmove_gnl(*ptr_fd, *ptr_fd + i, len - i);
		ft_memset_gnl(*ptr_fd + (len - i), 0, i);
	}
	*line = tmp;
	return (*line);
}

int		ft_get_res(int check, char **line, char **ptr_fd)
{
	int		res;
	char	*newline;

	newline = ft_tr_strchr(*ptr_fd, '\n');
	if (check == -1)
	{
		free(*ptr_fd);
		*ptr_fd = NULL;
		res = -1;
	}
	else if (check == 0 && !newline)
	{
		*line = ft_line_content(newline, line, ptr_fd);
		res = 0;
		free(*ptr_fd);
		*ptr_fd = NULL;
	}
	else
	{
		*line = ft_line_content(newline, line, ptr_fd);
		res = 1;
	}
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char	*ptr[FD_INDEX];
	char		tmp_buff[BUFFER_SIZE + 1];
	char		*tmp_ptr;
	int			check;

	if (fd < 0 || !line)
		return (-1);
	while ((check = read(fd, tmp_buff, BUFFER_SIZE)) > 0)
	{
		tmp_buff[check] = '\0';
		if (ptr[fd] == NULL)
			ptr[fd] = ft_tr_strdup(tmp_buff, NULL);
		else
		{
			tmp_ptr = ft_strjoin_gnl(ptr[fd], tmp_buff);
			free(ptr[fd]);
			ptr[fd] = tmp_ptr;
		}
		if (ft_tr_strchr(ptr[fd], '\n'))
			break ;
	}
	return (ft_get_res(check, line, &ptr[fd]));
}
