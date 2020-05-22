/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:17:51 by kmin              #+#    #+#             */
/*   Updated: 2020/05/20 19:40:36 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int hor_ray_set(t_player *p)
{
    p->hor.y_intercept = floor(p->unit.posy);
	p->hor.y_intercept += p->ray.FacingDown ? 1 : 0;
	p->hor.x_intercept = p->unit.posx + ((p->hor.y_intercept - p->unit.posy) / tan(p->ray.angle));
	p->hor.y_step = 1;
	p->hor.y_step *= p->ray.FacingUp ? -1 : 1;
	p->hor.x_step = 1 / tan(p->ray.angle);
	p->hor.x_step *= (p->ray.FacingLeft && p->hor.x_step > 0) ? -1: 1;
	p->hor.x_step *= (p->ray.FacingRight && p->hor.x_step < 0) ? -1 : 1;
	p->hor.nexttouchX = p->hor.x_intercept;
	p->hor.nexttouchY = p->hor.y_intercept;
	if (p->ray.FacingUp)
		p->hor.nexttouchY -= 0.0001;
}

int ver_ray_set(t_player *p)
{
    p->ver.x_intercept = floor(p->unit.posx);
	p->ver.x_intercept += p->ray.FacingRight ? 1 : 0;
	p->ver.y_intercept = p->unit.posy + (p->ver.x_intercept - p->unit.posx) * tan(p->ray.angle);
	p->ver.x_step = 1;
	p->ver.x_step *= p->ray.FacingLeft ? -1 : 1;
	p->ver.y_step = 1 * tan(p->ray.angle);
	p->ver.y_step *= (p->ray.FacingUp && p->ver.y_step > 0) ? -1 : 1;
	p->ver.y_step *= (p->ray.FacingDown && p->ver.y_step < 0) ? -1 : 1;
	p->ver.nexttouchX = p->ver.x_intercept;
	p->ver.nexttouchY = p->ver.y_intercept;
	if (p->ray.FacingLeft)
		p->ver.nexttouchX -= 0.0001;
}