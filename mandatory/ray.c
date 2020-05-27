/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:31:30 by kmin              #+#    #+#             */
/*   Updated: 2020/05/23 20:58:17 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ray_facing_dir(t_player *p)
{
	p->ray.facingdown = p->ray.angle > 0 && p->ray.angle < M_PI;
	p->ray.facingup = !(p->ray.facingdown);
	p->ray.facingright = p->ray.angle < 0.5 * M_PI || p->ray.angle > 1.5 * M_PI;
	p->ray.facingleft = !(p->ray.facingright);
	return (0);
}

int	ray(t_player *p, int *in_while_loop)
{
	double dist;
	double angle;

	if (*in_while_loop == TRUE)
		p->ray.angle += (double)FOV_ANGLE / p->scr.width;
	else
		*in_while_loop = TRUE;
	p->ray.angle = normalizeangle(p->ray.angle);
	ray_facing_dir(p);
	return (0);
}

int	hor(t_player *p)
{
	double y;
	double x;

	hor_ray_set(p);
	while (p->hor.found_hit == FALSE)
	{
		if (haswallat(p, p->hor.nextx, p->hor.nexty))
		{
			p->hor.found_hit = TRUE;
			p->hor.hitx = p->hor.nextx;
			p->hor.hity = p->hor.nexty;
			break ;
		}
		else
		{
			p->hor.nextx += p->hor.x_step;
			p->hor.nexty += p->hor.y_step;
		}
	}
	return (0);
}

int	ver(t_player *p)
{
	double x;
	double y;

	ver_ray_set(p);
	while (p->ver.found_hit == FALSE)
	{
		if (haswallat(p, p->ver.nextx, p->ver.nexty))
		{
			p->ver.found_hit = TRUE;
			p->ver.hitx = p->ver.nextx;
			p->ver.hity = p->ver.nexty;
			break ;
		}
		else
		{
			p->ver.nextx += p->ver.x_step;
			p->ver.nexty += p->ver.y_step;
		}
	}
	return (0);
}

int	dis(t_player *p)
{
	p->dis.hordis = (p->hor.found_hit) ?
	distance(p->unit.posx, p->unit.posy, p->hor.hitx, p->hor.hity)
	: __INT_MAX__;
	p->dis.verdis = (p->ver.found_hit) ?
	distance(p->unit.posx, p->unit.posy, p->ver.hitx, p->ver.hity)
	: __INT_MAX__;
	p->dis.hitx = (p->dis.hordis < p->dis.verdis) ? p->hor.hitx : p->ver.hitx;
	p->dis.hity = (p->dis.hordis < p->dis.verdis) ? p->hor.hity : p->ver.hity;
	p->dis.dis = (p->dis.hordis < p->dis.verdis) ?
		p->dis.hordis : p->dis.verdis;
	p->dis.washitver = (p->dis.verdis < p->dis.hordis);
	p->ray.side = (p->dis.dis == p->dis.verdis) ? 1 : 0;
	p->spr.wallhit[p->ray.id] = p->dis.dis;
	return (0);
}
