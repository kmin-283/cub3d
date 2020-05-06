/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:23:02 by kmin              #+#    #+#             */
/*   Updated: 2020/05/06 15:13:52 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(int key, t_player *p)
{
	free(p->map.map);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free(p->mlx_ptr);
	exit(0);
	return (0);
}

int key_press(int key, t_player *p)
{
    int moveStep;
    int newUnitX;
    int newUnitY;

	if (key == KEY_UP)
	{
		p->unit.walkDirection = 1;
        moveStep = p->unit.walkDirection * p->unit.moveSpeed;
        newUnitX = p->unit.x + cos(p->unit.rotationAngle) * moveStep;
        newUnitY = p->unit.y + sin(p->unit.rotationAngle) * moveStep;
        if (!hasWallAt(newUnitX, newUnitY))
        {
            p->unit.x = newUnitX;
            p->unit.y = newUnitY;
        }
	}
	else if (key == KEY_DOWN)
	{
		p->unit.walkDirection = -1;
        moveStep = p->unit.walkDirection * p->unit.moveSpeed;
        newUnitX = p->unit.x + cos(p->unit.rotationAngle) * moveStep;
        newUnitY = p->unit.y + sin(p->unit.rotationAngle) * moveStep;
        if (!hasWallAt(newUnitX, newUnitY))
        {
            p->unit.x = newUnitX;
            p->unit.y = newUnitY;
        }
	}
	else if (key == KEY_RIGHT)
	{
		p->unit.turnDirection = 1;
        p->unit.rotationAngle += p->unit.turnDirection * p->unit.rotationSpeed;
	}
	else if (key == KEY_LEFT)
	{
		p->unit.turnDirection = -1;
        p->unit.rotationAngle += p->unit.turnDirection * p->unit.rotationSpeed;
	}
    draw(p);
	return (0);
}

int key_release(int key, t_player *p)
{
	if (key == KEY_UP)
	{
		p->unit.walkDirection = 0;
	}
	else if (key == KEY_LEFT)
	{
		p->unit.walkDirection = 0;
	}
	else if (key == KEY_RIGHT)
	{
		p->unit.turnDirection = 0;
	}
	else if (key == KEY_DOWN)
	{
		p->unit.turnDirection = 0;
	}
	return (0);
}