/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:08 by kmin              #+#    #+#             */
/*   Updated: 2020/05/06 19:21:51 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int hasWallAt(int x, int y)
{
	int mapIndexX;
	int mapIndexY;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
		return TRUE;
	mapIndexX = (int)floor(x / TILE_SIZE);
	mapIndexY = (int)floor(y / TILE_SIZE);
	return (worldMap[mapIndexY][mapIndexX] != 0);
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