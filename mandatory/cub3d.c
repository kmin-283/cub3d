/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:08 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 11:35:50 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		haswallat(t_player *p, int x, int y)
{
	int mapindexx;
	int mapindexy;

	if (x < 0 || y < 0 || y > p->map.height - 1 || x > p->map.width[y])
		return (TRUE);
	mapindexx = x;
	mapindexy = y;
	return (p->map.map[mapindexy][mapindexx] == '1');
}

double	normalizeangle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (hypot((x2 - x1), (y2 - y1)));
}
