/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:58:23 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 22:04:15 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int mapColor(t_player *p, char *line, unsigned int *addr)
{
    int r;
    int g;
    int b;

    if (*addr != 0)
        return (error(FLOOR_CEILING_ERROR));
    line += 2;
    r = ft_atoi(line);
    while(ft_isdigit(*line))
        line++;
    line++;
    g = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    line++;
    b = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    while (isWhitespace(*line))
        line++;
    if (*line != '\0' || r > 255 || g > 255 || b > 255)
        return (error(COLOR_ERROR));
    *addr = (int)pow(255, 2) * r + 255*g + b;
    return (0);
}

int mapTexture(t_player *p, char *line, unsigned int **addr, void **img)
{
    int ret;
    int d[5];

    if (*addr != NULL)
        return(error(TEXTURE_ERROR));
    while (!(isWhitespace(*line)))
        line++;
    line++;
    ret = -1;
    if (nameCheck(line, ".xpm"))
    {
        ret = 0;
        if ((*img = mlx_xpm_file_to_image(p->mlx_ptr, line, &d[0], &d[1])) != NULL)
            *addr = (unsigned int *)mlx_get_data_addr(*img, &d[2], &d[3], &d[4]);
    }
    return (ret);
}

int screenRange(t_player *p, char *line)
{
    line += 2;
    if (p->scr.width != 0 || p->scr.height != 0)
        return (error(R_ERROR));
    p->scr.width = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    line++;
    p->scr.height = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    while (isWhitespace(*line))
        line++;
    if (p->scr.width > 2500)//1920*1080에 맞게 바꿔줄 것//
        p->scr.width = 1000;
    if (p->scr.height > 2500)
        p->scr.height = 1000;
    if (p->scr.width <= 0 || p->scr.height <= 0 || *line != '\0')
		return (error(R_ERROR));
    return (0);
}

int parsing_cubfile(t_player *p, char *line)
{
    int i;
    int ret;

    i = 0;
    while (isWhitespace(line[i]))
        i++;
    if (line[i] == 'R' && line[i + 1] == ' ')
        ret = screenRange(p, line);
    else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = mapTexture(p, line, &p->tex.no, &p->tex.n_img);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = mapTexture(p, line, &p->tex.so, &p->tex.s_img);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		ret = mapTexture(p, line, &p->tex.we, &p->tex.w_img);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		ret = mapTexture(p, line, &p->tex.ea, &p->tex.e_img);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		ret = mapTexture(p, line, &p->tex.sp, &p->tex.sp_img);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		ret = mapColor(p, line, &p->tex.f);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ret = mapColor(p, line, &p->tex.c);
    else if (line[i] == '1' && line[i + 1] != '\0')
		ret = mapGrid(p, line);
    return (ret);
}

int init_map(t_player *p, char *argv1)
{
    int     ret;
    int     val;
    int     fd;
    char    *line;

    if ((fd = open(argv1, O_RDONLY)) == -1)
        return (error(OPEN_ERROR));
    while ((ret = get_next_line(fd, &line)) > 0 && val != -1)
    {
        val = parsing_cubfile(p, line);
        free(line);
    }
    if (val == 0)
        val = parsing_cubfile(p, line);
    free(line);
    close(fd);
    if (val == 0)
        val = init_unit(p);
    if (val == 0)
        val = setMapWidth(p);
    return (val);
}