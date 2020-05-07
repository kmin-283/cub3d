/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:08 by kmin              #+#    #+#             */
/*   Updated: 2020/05/07 19:29:54 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int hasWallAt(t_player *p, int x, int y)
{
	int mapIndexX;
	int mapIndexY;

	if (x < 0 || y < 0 || (y / TILE_SIZE) > p->map.height - 1 || (x / TILE_SIZE) > (p->map.width[y / TILE_SIZE][1] - 1))
		return TRUE;
	mapIndexX = (int)floor(x / TILE_SIZE);
	mapIndexY = (int)floor(y / TILE_SIZE);
	return (p->map.map[mapIndexY][mapIndexX] == '1');
}

double normalizeAngle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double distanceBetweenPoint(int x1, int y1, int x2, int y2)
{
	return (hypot((x2 - x1), (y2- y1)));
}