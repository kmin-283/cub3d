/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 15:26:48 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int setUnitPos(t_player *p)
{
    int i;

    i = 0;
    while (p->map.map[p->unit.y][i])
    {
        if (p->map.map[p->unit.y][i] == 'W' || p->map.map[p->unit.y][i] == 'E' ||
        p->map.map[p->unit.y][i] == 'N' || p->map.map[p->unit.y][i] == 'S')
            p->unit.x = (i * TILE_SIZE) + TILE_SIZE / 2;
        i++;
    }
    p->unit.y = (p->unit.y * TILE_SIZE) + TILE_SIZE / 2;
    return (0);
}

int	init_unit(t_player *p)
{
    setUnitPos(p);
	p->unit.radius = 4;
	p->unit.turnDirection = 0;
	p->unit.walkDirection = 0;
	p->unit.moveSpeed = 4;
	p->unit.rotationSpeed = (4 * (M_PI / 180));
}