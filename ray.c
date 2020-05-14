/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:31:30 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 20:23:48 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ray_facing_dir(t_player *p)
{
	p->ray.FacingDown = p->ray.angle > 0 && p->ray.angle < M_PI;
	p->ray.FacingUp = !(p->ray.FacingDown);
	p->ray.FacingRight = p->ray.angle < 0.5 * M_PI || p->ray.angle > 1.5 * M_PI;
	p->ray.FacingLeft = !(p->ray.FacingRight);
}

int ray(t_player *p, int *in_while_loop)
{
	if (*in_while_loop == TRUE)
		p->ray.angle += (double)FOV_ANGLE / p->scr.width;
	else
		*in_while_loop = TRUE;
	p->ray.angle = normalizeAngle(p->ray.angle);
	ray_facing_dir(p);
}

int hor(t_player *p)
{
	hor_ray_set(p);
	while (p->hor.nexttouchX >= 0 && p->hor.nexttouchY >=0 && p->hor.nexttouchY <= p->scr.height\
	&& p->hor.nexttouchX <= p->scr.width)
	{
		if (hasWallAt(p, p->hor.nexttouchX, p->hor.nexttouchY))
		{
			p->hor.foundWallHit = TRUE;
			p->hor.wallHitX = p->hor.nexttouchX;
			p->hor.wallHitY = p->hor.nexttouchY;
			break;
		}
		else
		{
			p->hor.nexttouchX += p->hor.x_step;
			p->hor.nexttouchY += p->hor.y_step;
		}
	}
}

int ver(t_player *p)
{
	ver_ray_set(p);
	while (p->ver.nexttouchX >= 0 && p->ver.nexttouchY >=0 && p->ver.nexttouchY <= p->scr.height\
	&& p->ver.nexttouchX <= p->scr.width)
	{
		if (hasWallAt(p, p->ver.nexttouchX, p->ver.nexttouchY))
		{
			p->ver.foundWallHit = TRUE;
			p->ver.wallHitX = p->ver.nexttouchX;
			p->ver.wallHitY = p->ver.nexttouchY;
			break;
		}
		else
		{
			p->ver.nexttouchX += p->ver.x_step;
			p->ver.nexttouchY += p->ver.y_step;
		}
	}
}

int dis(t_player *p)
{
	p->dis.horDis = (p->hor.foundWallHit) ?
	distanceBetweenPoint(p->unit.x, p->unit.y, p->hor.wallHitX, p->hor.wallHitY)
	: __INT_MAX__;
	p->dis.verDis = (p->ver.foundWallHit) ?
	distanceBetweenPoint(p->unit.x, p->unit.y, p->ver.wallHitX, p->ver.wallHitY)
	: __INT_MAX__;
	p->dis.final_wallHitX = (p->dis.horDis < p->dis.verDis) ? p->hor.wallHitX : p->ver.wallHitX;
	p->dis.final_wallHitY = (p->dis.horDis < p->dis.verDis) ? p->hor.wallHitY : p->ver.wallHitY;
	p->dis.final_dis = (p->dis.horDis < p->dis.verDis) ? p->dis.horDis : p->dis.verDis;
	p->dis.wasHitVer = (p->dis.verDis < p->dis.horDis);
	p->ray.side = (p->dis.final_dis == p->dis.verDis) ? 1 : 0;
	p->spr.wallhit[p->ray.id] = p->dis.final_dis;
}