/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_and_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/31 13:36:04 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		parsing_sprites(t_player *p, char *line, int i, int *ret)
{
	if (line[i] == 'S' && line[i + 1] == ' ')
		*ret = maptexture(p, line, &p->tex.sp, &p->tex.sp_img);
	else if (line[i] == 'D' && line[i + 1] == ' ')
		*ret = maptexture(p, line, &p->tex.sp_d, &p->tex.sp_d_img);
	else if (line[i] == 'T' && line[i + 1] == ' ')
		*ret = maptexture(p, line, &p->tex.sp_t, &p->tex.sp_t_img);
	return (0);
}

void	sprite_list(t_player *p)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (p->sprite != NULL)
		free(p->sprite);
	if (!(p->sprite = ft_calloc(p->map.spr_num, sizeof(t_sprite))))
		error(SPRITE_ALLOCATION_ERROR);
	while (i < p->map.height)
	{
		j = 0;
		while (j < p->map.width[i])
		{
			if (p->map.map[i][j] == '2' || p->map.map[i][j] == '3' ||
					p->map.map[i][j] == '4')
			{
				p->sprite[k].x = (double)j + 0.5;
				p->sprite[k++].y = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
}

int		sprite_set(t_player *p, double dist, int *i, double xloc)
{
	p->spr.dis_plane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	p->spr.strip_height = (1 / dist) * p->spr.dis_plane;
	p->spr.start = (p->scr.height - p->spr.strip_height) / 2;
	*i = xloc;
	if (p->spr.strip_height > p->scr.height)
		p->spr.strip_height = 0;
	return (0);
}

int		sprite_start_point(t_player *p, int tex_size, int i)
{
	int x;
	int y;

	x = 0;
	if (p->tex.sp == NULL || p->tex.sp_d == NULL ||
			p->tex.sp_t == NULL)
		return (error(TEXTURE_ERROR));
	while (x < tex_size)
	{
		y = 0;
		while (y < tex_size)
		{
			if (p->tex.sp[x + y * tex_size] != -16777216)
			{
				p->sprite[i].start_p = x;
				return (0);
			}
			y++;
		}
		x++;
	}
	return (error(TEXTURE_ERROR));
}

int		init_unit(t_player *p)
{
	p->unit.radius = 4;
	p->unit.turndirection = 0;
	p->unit.walkdirection = 0;
	p->unit.movespeed = 5;
	p->unit.rotationspeed = (3 * (M_PI / 180));
	return (0);
}
