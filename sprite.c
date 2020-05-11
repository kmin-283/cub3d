/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:03:35 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 22:30:21 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int sprite_draw(t_player *p, int i)
{
    int size;
    int loc;
    int k;
    int j;

    size = p->scr.height / /* p->spr.cor_dis[i][2] / */ 2;
   	loc = p->spr.cor_dis[i][1];
    k = 0;
    for(int a=0;a<64;a++)
    {
        for(int b=0;b<64;b++)
        {
            p->img_addr[a + (size + b) * p->scr.width] = p->tex.sp[a + b * 64];
        }
    }
    return (0);
}

int sprite_order(t_player *p)
{
    double *tmp;
    int i;
	int	j;

	i = 0;
	while (i < p->spr.n - 1)
	{
		j = i + 1;
		while (j < p->spr.n)
		{
			if (p->spr.cor_dis[i][2] > p->spr.cor_dis[j][2])
			{
				tmp = p->spr.cor_dis[i];
				p->spr.cor_dis[i] = p->spr.cor_dis[j];
				p->spr.cor_dis[j] = tmp;
			}
			j++;
		}
		i++;
	}
    return (0);
}

int sprite(t_player *p)
{
    int i;

    i = 0;
    while (i < p->spr.n)
    {
        p->spr.cor_dis[i][2] = hypot(p->spr.cor_dis[i][1] - p->unit.x, p->spr.cor_dis[i][0] - p->unit.y);
        i++;
    }
    sprite_order(p);
    i = 0;
    while (i < p->spr.n)
    {
        sprite_draw(p, i);
        i++;
    }
    return (0);
}