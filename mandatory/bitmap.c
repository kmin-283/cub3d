/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:50:55 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 20:52:31 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int bmp_header(t_player *p, int fd, int file_size)
{
    char    header[54];

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
    header[26] = (unsigned char)0x20;
    write(fd, header, 54);
    return (1);
}

int bmp_data(t_player *p, int fd, int file_size)
{
    char *ptr;

    ptr = (char *)p->img_addr;
    write(fd, ptr, file_size - 54);
    return (0);
}

int init_bitmap(t_player *p)
{
    int fd;
    int file_size;
    int ret;

    if ((fd = open("save.bmp", O_CREAT, O_RDWR, S_IRWXU)) < 0)
        return (error(BITMAP_OPEN_ERROR));
    file_size = 54 + (p->scr.width * p->scr.height) * 4;
    ret = bmp_header(p, fd, file_size);
    ret = bmp_data(p, fd, file_size);
    return (ret);
}