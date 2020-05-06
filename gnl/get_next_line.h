/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:11:11 by kmin              #+#    #+#             */
/*   Updated: 2020/05/05 18:10:59 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif
# define FD_INDEX 4096
# include <unistd.h>
# include <stdlib.h>
int		ft_strlen_gnl(const char *str);
void	*ft_memset_gnl(void *dest,int c, size_t   len);
void	*ft_calloc_gnl(size_t number, size_t size);
char	*ft_tr_strdup(const char *str, char *newline);
char    *ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_tr_strchr(const char *s, int c);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);
char	*ft_line_content(char *newline, char **line, char **ptr_fd);
int		ft_get_res(int check,  char **line, char **ptr_fd);
int		get_next_line(int fd, char **line);
#endif