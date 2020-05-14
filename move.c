/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:13:05 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 14:42:24 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int unit_move(t_player *p)
{
	if (p->key.w)
		moveBackandForth(KEY_UP, p);
	if (p->key.s)
        moveBackandForth(KEY_DOWN, p);
	if (p->key.d)
		moveLeftandRight(KEY_RIGHT, p);
	if (p->key.a)
		moveLeftandRight(KEY_LEFT, p);
	if (p->key.esc)
		ft_close(1, p);
	if (p->key.left)
		rotate(LEFT_ARROW, p);
	if (p->key.right)
		rotate(RIGHT_ARROW, p);
    draw(p, FALSE);
	return (0);
}

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