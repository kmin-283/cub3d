/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:21:19 by kmin              #+#    #+#             */
/*   Updated: 2020/05/20 11:07:56 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
    c == '\v' || c == 'f' || c == 'r');
}

int setPosition(t_player *p, char c)
{
    if (c == 'N')
    {
        p->unit.diry = -1;
        p->unit.rotationAngle = (3 * M_PI) / 2;
    }
    else if (c == 'S')
    {
        p->unit.diry = 1;
        p->unit.rotationAngle = M_PI / 2;
    }
    else if (c == 'E')
    {
        p->unit.dirx = 1;
        p->unit.rotationAngle = 2 * M_PI;
    }
    else if (c == 'W')
    {
        p->unit.dirx = -1;
        p->unit.rotationAngle = M_PI;
    }
    if (p->unit.pos != 1)
        return (-1);
    return (0);
}

int isWall(char c)
{
    return (c == ' ' || c == '1');
}