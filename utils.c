/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:21:19 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 21:09:55 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int sprite_cor(t_player *p, int row, int col)
{
    double **ptr;
    int i;

    i = 0;
    if(!(ptr = (double **)ft_calloc(p->spr.n + 1, sizeof(double *))))
        return (error(SPRITE_ALLOCATION_ERROR));
    while (i < p->spr.n)
        ptr[i++] = p->spr.cor_dis[i];
    if (!(ptr[i] = (double *)ft_calloc(3, sizeof(double))))
        return (error(SPRITE_ALLOCATION_ERROR));
    ptr[i][0] = row * TILE_SIZE + TILE_SIZE / 2;
    ptr[i][1] = col * TILE_SIZE + TILE_SIZE / 2;
    if (p->spr.cor_dis)
    {
        free(p->spr.cor_dis);
        p->spr.cor_dis = NULL;
    }
    p->spr.cor_dis = ptr;
    p->spr.n++;
    return (0);
}

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
        p->unit.rotationAngle = 2 * M_PI;
    else if (c == 'W')
        p->unit.rotationAngle = M_PI;
    else
        return (0);
    p->unit.y = p->map.height;
    return (1);
}

int isWall(char c)
{
    return (c == ' ' || c == '1');
}