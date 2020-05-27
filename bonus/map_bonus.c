/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:58:23 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 13:24:25 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mapcolor(t_player *p, char *line, unsigned int *addr)
{
	int r;
	int g;
	int b;

	if (*addr != 0)
		return (error(FLOOR_CEILING_ERROR));
	line += 2;
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (iswhitespace(*line))
		line++;
	if (*line != '\0' || r > 255 || g > 255 || b > 255)
		return (error(COLOR_ERROR));
	*addr = (int)pow(255, 2) * r + 255 * g + b;
	return (0);
}

int	maptexture(t_player *p, char *line, unsigned int **addr, void **img)
{
	int ret;
	int d[5];

	if (*addr != NULL)
		return (error(TEXTURE_ERROR));
	while (!(iswhitespace(*line)))
		line++;
	line++;
	ret = -1;
	if (namecheck(line, ".xpm"))
	{
		ret = 0;
		if ((*img = mlx_xpm_file_to_image(p->mlx_ptr, line,
						&d[0], &d[1])) != NULL)
			*addr = (unsigned int *)mlx_get_data_addr(*img, &d[2],
					&d[3], &d[4]);
	}
	return (ret);
}

int	screenrange(t_player *p, char *line)
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
	while (iswhitespace(*line))
		line++;
	if (p->scr.width > 2560)
		p->scr.width = 25600;
	if (p->scr.height > 1400)
		p->scr.height = 1400;
	if (p->scr.width <= 0 || p->scr.height <= 0 || *line != '\0')
		return (error(R_ERROR));
	return (0);
}

int	parsing_cubfile(t_player *p, char *line)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	skip_space(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		ret = screenrange(p, line);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = maptexture(p, line, &p->tex.no, &p->tex.n_img);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = maptexture(p, line, &p->tex.so, &p->tex.s_img);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		ret = maptexture(p, line, &p->tex.we, &p->tex.w_img);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		ret = maptexture(p, line, &p->tex.ea, &p->tex.e_img);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		ret = maptexture(p, line, &p->tex.f, &p->tex.f_img);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ret = maptexture(p, line, &p->tex.c, &p->tex.c_img);
	else if (line[i] == '1' && line[i + 1] != '\0')
		ret = mapgrid(p, line);
	parsing_sprites(p, line, i, &ret);
	return (ret);
}

int	init_map(t_player *p, char *argv1)
{
	int		ret;
	int		val;
	int		fd;
	char	*line;

	val = 0;
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
		val = check_and_set(p);
	return (val);
}
