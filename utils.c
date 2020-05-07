/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:21:19 by kmin              #+#    #+#             */
/*   Updated: 2020/05/07 13:32:31 by kmin             ###   ########.fr       */
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
        p->unit.rotationAngle = (3 * M_PI) / 2;
    else if (c == 'S')
        p->unit.rotationAngle = M_PI / 2;
    else if (c == 'E')
        p->unit.rotationAngle = M_PI;
    else if (c == 'W')
        p->unit.rotationAngle = 0;
    else
        return (0);
    p->unit.y = p->map.height;
    return (1);
}

int isWall(char c)
{
    return (c == ' ' || c == '1');
}