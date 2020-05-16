/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:03:35 by kmin              #+#    #+#             */
/*   Updated: 2020/05/17 00:17:21 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int fill_sp_tex(t_player *p, double x, double scale)
{
    unsigned int color;

    color = p->tex.sp[(int)p->spr.x_cor + (int)(p->spr.y_cor) * 64];
    p->spr.y_cor += scale;
    if (p->spr.y_cor > 64)
        p->spr.y_cor = 0;
    return (color);
}

int sprite_draw(t_player *p, double xloc, double dist, int k)
{
    int i;
    int j;
    unsigned int color;
    double scale;

    p->spr.distance_projection_plane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	p->spr.sprite_strip_height = (1 / dist) * p->spr.distance_projection_plane;
    p->spr.start = (p->scr.height - p->spr.sprite_strip_height) / 2;
    i = xloc;
    scale = 64 / p->spr.sprite_strip_height;
    if (p->spr.sprite_strip_height > p->scr.height)
        p->spr.sprite_strip_height = 0;
    while (i < xloc + p->spr.sprite_strip_height)
    {
        j = p->spr.start;
        while (j < p->spr.start + p->spr.sprite_strip_height)
        {
            color = fill_sp_tex(p, p->spr.x_cor, scale);
            if (color != 0 && i >= 0 && i < p->scr.width && j >= 0 && j < p->scr.height && p->spr.wallhit[i] > dist)
                p->img_addr[i + j * p->scr.width] = color;
            j++;
        }
        p->spr.x_cor += scale;
        i++;
    }
}

int sprite_locate(t_player *p, int i, double angle)
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
}

int sprite_order(t_player *p)
{
    t_sprite tmp;
    int i;
	int	j;

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

int sprite(t_player *p)
{
    int i;
    double angle;

    i = 0;
    angle = normalizeAngle(p->unit.rotationAngle) * 180 / M_PI;
    while (i < p->map.spr_num)
    {
        p->sprite[i].d = hypot(p->sprite[i].x - p->unit.posx, p->sprite[i].y - p->unit.posy);
        p->sprite[i].a = atan2(p->sprite[i].y - p->unit.posy, p->sprite[i].x - p->unit.posx);
        p->sprite[i].a = normalizeAngle(p->sprite[i].a) * 180 / M_PI;
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