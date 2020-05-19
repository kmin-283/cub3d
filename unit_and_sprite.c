/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_and_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/19 19:25:15 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int sprite_list(t_player *p)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    if (p->sprite != NULL)
        free(p->sprite);
    if (!(p->sprite = ft_calloc(p->map.spr_num, sizeof(t_sprite))))
        return (error(SPRITE_ALLOCATION_ERROR));
    while (i < p->map.height)
    {
        j = 0;
        while (j < p->map.width[i])
        {
            if (p->map.map[i][j] == '2')
            {
                p->sprite[k].x = (double)j + 0.5;
                p->sprite[k++].y = (double)i + 0.5;
            }
            j++;
        }
        i++;
    }
    return (0);
}

int setUnitPos(t_player *p)
{
    int i;

    i = 0;
    if (p->unit.pos > 1)
        return (error(MAP_DOUBLE_ERROR));
    if (p->map.map)
    {
        while (p->map.map[p->unit.y][i])
        {
            if (p->map.map[p->unit.y][i] == 'W' || p->map.map[p->unit.y][i] == 'E' ||
            p->map.map[p->unit.y][i] == 'N' || p->map.map[p->unit.y][i] == 'S')
                p->unit.x = (i * TILE_SIZE) + TILE_SIZE / 2;
            i++;
        }
        p->unit.y = (p->unit.y * TILE_SIZE) + TILE_SIZE / 2;
    }
    else
    {
        while (i < p->map.height)
            free(p->map.map[i++]);
        free(p->map.map);
    }
    return (0);
}

int	init_unit(t_player *p)
{
    int ret;

    if ((ret = setUnitPos(p)) == -1)
        return (-1);
	p->unit.radius = 4;
	p->unit.turnDirection = 0;
	p->unit.walkDirection = 0;
	p->unit.moveSpeed = 10;
	p->unit.rotationSpeed = (10 * (M_PI / 180));
    return (0);
}