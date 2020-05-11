/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:31:30 by kmin              #+#    #+#             */
/*   Updated: 2020/05/08 19:02:42 by kmin             ###   ########.fr       */
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
	p->hor.y_intercept = floor(p->unit.y / TILE_SIZE) * TILE_SIZE;
	p->hor.y_intercept += p->ray.FacingDown ? TILE_SIZE : 0;
	p->hor.x_intercept = p->unit.x + ((p->hor.y_intercept - p->unit.y) / tan(p->ray.angle));
	p->hor.y_step = TILE_SIZE;
	p->hor.y_step *= p->ray.FacingUp ? -1 : 1;
	p->hor.x_step = TILE_SIZE / tan(p->ray.angle);
	p->hor.x_step *= (p->ray.FacingLeft && p->hor.x_step > 0) ? -1: 1;
	p->hor.x_step *= (p->ray.FacingRight && p->hor.x_step < 0) ? -1 : 1;
	p->hor.nexttouchX = p->hor.x_intercept;
	p->hor.nexttouchY = p->hor.y_intercept;
	if (p->ray.FacingUp)
		p->hor.nexttouchY--;
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
	p->ver.x_intercept = floor(p->unit.x / TILE_SIZE) * TILE_SIZE;
	p->ver.x_intercept += p->ray.FacingRight ? TILE_SIZE : 0;
	p->ver.y_intercept = p->unit.y + (p->ver.x_intercept - p->unit.x) * tan(p->ray.angle);
	p->ver.x_step = TILE_SIZE;
	p->ver.x_step *= p->ray.FacingLeft ? -1 : 1;
	p->ver.y_step = TILE_SIZE * tan(p->ray.angle);
	p->ver.y_step *= (p->ray.FacingUp && p->ver.y_step > 0) ? -1 : 1;
	p->ver.y_step *= (p->ray.FacingDown && p->ver.y_step < 0) ? -1 : 1;
	p->ver.nexttouchX = p->ver.x_intercept;
	p->ver.nexttouchY = p->ver.y_intercept;
	if (p->ray.FacingLeft)
		p->ver.nexttouchX--;
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
}