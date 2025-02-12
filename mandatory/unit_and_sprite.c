/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_and_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/29 14:23:27 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	sprite_list(t_player *p)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (p->sprite != NULL)
		free(p->sprite);
	if (!(p->sprite = ft_calloc(p->map.spr_num, sizeof(t_sprite))))
		return (error(SPRITE_ALLOCATION_ERROR));
	while (i < p->map.height)
	{
		j = 0;
		while (j < p->map.width[i])
		{
			if (p->map.map[i][j] == '2')
			{
				p->sprite[k].x = (double)j + 0.5;
				p->sprite[k++].y = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	sprite_set(t_player *p, double dist, int *i, double xloc)
{
	p->spr.dis_plane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	p->spr.strip_height = (1 / dist) * p->spr.dis_plane;
	p->spr.start = (p->scr.height - p->spr.strip_height) / 2;
	*i = xloc;
	if (p->spr.strip_height > p->scr.height)
		p->spr.strip_height = 0;
	return (0);
}

int	sprite_start_point(t_player *p, int tex_size, int i)
{
	int x;
	int y;

	if (p->tex.sp == NULL)
		return (error(TEXTURE_ERROR));
	x = 0;
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

int	init_unit(t_player *p)
{
	p->unit.radius = 4;
	p->unit.turndirection = 0;
	p->unit.walkdirection = 0;
	p->unit.movespeed = 5;
	p->unit.rotationspeed = (3 * (M_PI / 180));
	return (0);
}
