/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:03:35 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 17:30:55 by kmin             ###   ########.fr       */
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
    int index;
    int h;
    double distanceProjectionPlane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	double spriteStripHeight = (64 / dist) * distanceProjectionPlane / 2;
    int start = (p->scr.height - spriteStripHeight) / 2;
    int i = xloc;
    int j;
    unsigned int color;
    double scale = 64 / spriteStripHeight;
    if (spriteStripHeight > p->scr.height)
        spriteStripHeight = 0;
    while (i < xloc + spriteStripHeight)
    {
        j = start;
        while (j < start + spriteStripHeight)
        {
            color = fill_sp_tex(p, p->spr.x_cor, scale);
            if (color != 0 && i >= 0 && i < p->scr.width && j >= 0 && j < p->scr.height && p->spr.wallhit[i] > dist)
                p->img_addr[i + j * p->scr.width] = color;
            j++;
        }
        p->spr.x_cor += scale;
        i++;
    }
    p->spr.x_cor = 0;
}

int sprite_locate(t_player *p, int i, double angle)
{
    double s_angle;
    double tmp_angle;
    double xloc;

    s_angle = angle - 33 - p->spr.cor_dis[i][3];
    tmp_angle = s_angle;
    s_angle = -s_angle;
    xloc = s_angle * p->scr.width / 66;
    if (s_angle < FOV_ANGLE * 180 / M_PI)
        p->spr.visible = TRUE;
    else
        p->spr.visible = FALSE;
    if (p->spr.visible == TRUE)
        sprite_draw(p, xloc, p->spr.cor_dis[i][2], i);
}
int sprite_order(t_player *p)
{
    double *tmp;
    int i;
	int	j;

	i = 0;
	while (i < p->spr.n - 1)
	{
		j = i + 1;
		while (j < p->spr.n)
		{
			if (p->spr.cor_dis[i][2] < p->spr.cor_dis[j][2])
			{
				tmp = p->spr.cor_dis[i];
				p->spr.cor_dis[i] = p->spr.cor_dis[j];
				p->spr.cor_dis[j] = tmp;
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
    while (i < p->spr.n)
    {
        p->spr.cor_dis[i][2] = hypot(p->spr.cor_dis[i][1] - p->unit.x, p->spr.cor_dis[i][0] - p->unit.y);
        p->spr.cor_dis[i][3] = atan2(p->spr.cor_dis[i][0] - p->unit.y, p->spr.cor_dis[i][1] - p->unit.x);
        p->spr.cor_dis[i][3] = normalizeAngle(p->spr.cor_dis[i][3]) * 180 / M_PI;
        i++;
    }
    sprite_order(p);
    i = 0;
    while (i < p->spr.n)
    {
        sprite_locate(p, i, angle);
        i++;
    }
    return (0);
}