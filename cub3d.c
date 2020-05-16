/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:08 by kmin              #+#    #+#             */
/*   Updated: 2020/05/16 22:26:08 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int hasWallAt(t_player *p, int x, int y)
{
	int mapIndexX;
	int mapIndexY;

	if (x < 0 || y < 0 || y > p->map.height || x > p->map.width[y])
		return TRUE;
	mapIndexX = x;
	mapIndexY = y;
	return (p->map.map[mapIndexY][mapIndexX] == '1');
}

double normalizeAngle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double distanceBetweenPoint(double x1, double y1, double x2, double y2)
{
	return (hypot((x2 - x1), (y2- y1)));
}