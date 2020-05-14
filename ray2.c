/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:17:51 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 20:22:08 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int hor_ray_set(t_player *p)
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
}

int ver_ray_set(t_player *p)
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
}