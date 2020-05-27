/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:50:55 by kmin              #+#    #+#             */
/*   Updated: 2020/05/27 10:15:47 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bmp_header(t_player *p, int fd, int file_size)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)0x42;
	header[1] = (unsigned char)0x4D;
	header[2] = (unsigned char)file_size;
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)0x36;
	header[14] = (unsigned char)0x28;
	header[18] = (unsigned char)p->scr.width;
	header[19] = (unsigned char)(p->scr.width >> 8);
	header[20] = (unsigned char)(p->scr.width >> 16);
	header[21] = (unsigned char)(p->scr.width >> 24);
	header[22] = (unsigned char)(p->scr.height);
	header[23] = (unsigned char)(p->scr.height >> 8);
	header[24] = (unsigned char)(p->scr.height >> 16);
	header[25] = (unsigned char)(p->scr.height >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)0x20;
	write(fd, header, 54);
	return (1);
}

int	bmp_data(t_player *p, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = p->scr.width * (p->scr.height - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < p->scr.width)
		{
			buffer[0] = (unsigned char)(p->img_addr[i]);
			buffer[1] = (unsigned char)(p->img_addr[i] >> 8);
			buffer[2] = (unsigned char)(p->img_addr[i] >> 16);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * p->scr.width;
	}
	return (0);
}

int	init_bitmap(t_player *p)
{
	int fd;
	int file_size;
	int ret;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	file_size = 54 + (p->scr.width * p->scr.height) * 4;
	ret = bmp_header(p, fd, file_size);
	ret = bmp_data(p, fd);
	return (ret);
}
