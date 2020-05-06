/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/06 19:14:54 by kmin             ###   ########.fr       */
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
            p->unit.x = i;
        i++;
    }
}

int	init_unit(t_player *p)
{
    setUnitPos(p);
    p->unit.x = SCREEN_WIDTH / 2;
    p->unit.y = SCREEN_HEIGHT / 7;
	p->unit.radius = 4;
	p->unit.turnDirection = 0;
	p->unit.walkDirection = 0;
	p->unit.moveSpeed = 4;
	p->unit.rotationSpeed = (3 * (M_PI / 180));
}