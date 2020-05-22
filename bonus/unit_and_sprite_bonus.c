/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_and_sprite_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:43:47 by kmin              #+#    #+#             */
/*   Updated: 2020/05/22 18:03:59 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	init_unit(t_player *p)
{
	p->unit.radius = 4;
	p->unit.turnDirection = 0;
	p->unit.walkDirection = 0;
	p->unit.moveSpeed = 5;
	p->unit.rotationSpeed = (3 * (M_PI / 180));
    return (0);
}