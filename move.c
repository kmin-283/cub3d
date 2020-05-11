/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:13:05 by kmin              #+#    #+#             */
/*   Updated: 2020/05/07 23:10:10 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rotate(int key, t_player *p)
{
	if (key == RIGHT_ARROW)
		p->unit.turnDirection = 1;
	else if (key == LEFT_ARROW)
		p->unit.turnDirection = -1;
	p->unit.rotationAngle += p->unit.turnDirection * p->unit.rotationSpeed;
}

int	moveBackandForth(int key, t_player *p)
{
	double moveStep;
	int newUnitX;
	int newUnitY;

	if (key == KEY_UP)
		p->unit.walkDirection = 1;
	else if (key == KEY_DOWN)
		p->unit.walkDirection = -1;
	moveStep = p->unit.walkDirection * p->unit.moveSpeed;
    newUnitX = p->unit.x + cos(p->unit.rotationAngle) * moveStep;
	newUnitY = p->unit.y + sin(p->unit.rotationAngle) * moveStep;
    if (!hasWallAt(p, newUnitX, newUnitY))
    {
		p->unit.x = newUnitX;
		p->unit.y = newUnitY;
	}
}

int	moveLeftandRight(int key, t_player *p)
{
	double moveStep;
	int newUnitX;
	int newUnitY;

	if (key == KEY_LEFT)
		p->unit.walkDirection = 1;
	else if (key == KEY_RIGHT)
		p->unit.walkDirection = -1;
	moveStep = p->unit.walkDirection * p->unit.moveSpeed;
    newUnitX = p->unit.x + sin(p->unit.rotationAngle) * moveStep;
	newUnitY = p->unit.y - cos(p->unit.rotationAngle) * moveStep;
    if (!hasWallAt(p, newUnitX, newUnitY))
    {
		p->unit.x = newUnitX;
		p->unit.y = newUnitY;
	}
}