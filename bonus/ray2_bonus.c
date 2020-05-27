/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:17:51 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 11:19:08 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	hor_ray_set(t_player *p)
{
	p->hor.y_intercept = floor(p->unit.posy);
	p->hor.y_intercept += p->ray.facingdown ? 1 : 0;
	p->hor.x_intercept = p->unit.posx + ((p->hor.y_intercept - p->unit.posy) /
			tan(p->ray.angle));
	p->hor.y_step = 1;
	p->hor.y_step *= p->ray.facingup ? -1 : 1;
	p->hor.x_step = 1 / tan(p->ray.angle);
	p->hor.x_step *= (p->ray.facingleft && p->hor.x_step > 0) ? -1 : 1;
	p->hor.x_step *= (p->ray.facingright && p->hor.x_step < 0) ? -1 : 1;
	p->hor.nextx = p->hor.x_intercept;
	p->hor.nexty = p->hor.y_intercept;
	if (p->ray.facingup)
		p->hor.nexty -= 0.0001;
	return (0);
}

int	ver_ray_set(t_player *p)
{
	p->ver.x_intercept = floor(p->unit.posx);
	p->ver.x_intercept += p->ray.facingright ? 1 : 0;
	p->ver.y_intercept = p->unit.posy + (p->ver.x_intercept - p->unit.posx)
		* tan(p->ray.angle);
	p->ver.x_step = 1;
	p->ver.x_step *= p->ray.facingleft ? -1 : 1;
	p->ver.y_step = 1 * tan(p->ray.angle);
	p->ver.y_step *= (p->ray.facingup && p->ver.y_step > 0) ? -1 : 1;
	p->ver.y_step *= (p->ray.facingdown && p->ver.y_step < 0) ? -1 : 1;
	p->ver.nextx = p->ver.x_intercept;
	p->ver.nexty = p->ver.y_intercept;
	if (p->ray.facingleft)
		p->ver.nextx -= 0.0001;
	return (0);
}
