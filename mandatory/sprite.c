/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:03:35 by kmin              #+#    #+#             */
/*   Updated: 2020/05/29 14:08:33 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	fill_sp_tex(t_player *p, double x, double scale, int i)
{
	unsigned int color;

	color = p->tex.sp[(int)p->spr.x_cor + p->sprite[i].start_p +
		(int)(p->spr.y_cor) * 64];
	p->spr.y_cor += scale;
	if (p->spr.y_cor > 64)
		p->spr.y_cor = 0;
	return (color);
}

int				sprite_draw(t_player *p, double xloc, double dist, int k)
{
	int				i;
	int				j;
	unsigned int	color;

	sprite_set(p, dist, &i, xloc);
	while (i < xloc + p->spr.strip_height)
	{
		j = p->spr.start;
		while (j < p->spr.start + p->spr.strip_height)
		{
			color = fill_sp_tex(p, p->spr.x_cor, 64 / p->spr.strip_height, k);
			if (color != -16777216 && i >= 0 && i < p->scr.width &&
					j >= 0 && j < p->scr.height && p->spr.wallhit[i] > dist)
				p->img_addr[i + j * p->scr.width] = color;
			j++;
		}
		if (p->spr.x_cor + p->sprite[k].start_p < 63)
			p->spr.x_cor += (64 / p->spr.strip_height);
		i++;
	}
	return (0);
}

int				sprite_locate(t_player *p, int i, double angle)
{
	double s_angle;
	double tmp_angle;
	double xloc;

	s_angle = angle - 33 - p->sprite[i].a;
	if (s_angle > 180)
		s_angle -= 360;
	else if (s_angle < -180)
		s_angle += 360;
	tmp_angle = s_angle;
	s_angle = -s_angle;
	xloc = s_angle * p->scr.width / 66;
	if (s_angle < FOV_ANGLE * 180 / M_PI)
		p->sprite[i].visible = TRUE;
	else
		p->sprite[i].visible = FALSE;
	if (p->sprite[i].visible == TRUE)
		sprite_draw(p, xloc, p->sprite[i].d, i);
	p->spr.x_cor = 0;
	p->spr.y_cor = 0;
	return (0);
}

int				sprite_order(t_player *p)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < p->map.spr_num - 1)
	{
		j = i + 1;
		while (j < p->map.spr_num)
		{
			if (p->sprite[i].d < p->sprite[j].d)
			{
				tmp = p->sprite[i];
				p->sprite[i] = p->sprite[j];
				p->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				sprite(t_player *p)
{
	int		i;
	double	angle;

	i = 0;
	angle = normalizeangle(p->unit.angle) * 180 / M_PI;
	while (i < p->map.spr_num)
	{
		p->sprite[i].d = hypot(p->sprite[i].x - p->unit.posx,
				p->sprite[i].y - p->unit.posy);
		p->sprite[i].a = atan2(p->sprite[i].y - p->unit.posy,
				p->sprite[i].x - p->unit.posx);
		p->sprite[i].a = normalizeangle(p->sprite[i].a) * 180 / M_PI;
		i++;
	}
	sprite_order(p);
	i = 0;
	while (i < p->map.spr_num)
	{
		sprite_locate(p, i, angle);
		i++;
	}
	return (0);
}
