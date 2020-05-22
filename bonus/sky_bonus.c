/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:13:59 by kmin              #+#    #+#             */
/*   Updated: 2020/05/22 19:47:08 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int sky(t_player *p)
{
    unsigned int color;
    int index;
    
    if (p->tex.sky_ycor > 64)
        p->tex.sky_ycor = 0;
    else
        p->tex.sky_ycor += (double)64 / (p->scr.height / 2);
    index = floor(p->tex.sky_xcor) + floor(p->tex.sky_ycor) * 1024;
    color = p->tex.c[index];
    return (color);
}