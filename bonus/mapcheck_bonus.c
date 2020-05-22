/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:33:26 by kmin              #+#    #+#             */
/*   Updated: 2020/05/20 19:40:25 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int verify_space(t_player *p, int i, int k)
{
    int top;
    int left;

    top = 0;
    left = 0;
    if (i == 0)
        top = 1;
    else if (p->map.map[i - 1][k] == ' ' || p->map.map[i - 1][k] == '1')
        top = 1;
    if (k == 0)
        left = 1;
    else if (p->map.map[i][k - 1] == ' ' || p->map.map[i][k - 1] == '1')
        left = 1;
    if (top && left)
        return (1);
    else
        return (-1);
}

int verify_else(t_player *p, int i, int k)
{
    if (i == 0 || p->map.map[i - 1][k] == ' ')
        return (-1);
    else if (k == 0 || p->map.map[i][k - 1] == ' ')
        return (-1);
    else if (p->map.map[i][k + 1] == ' ' || p->map.map[i][k + 1] == '\0')
        return (-1);
    else if (i == p->map.height - 1)
        return (-1);
}

int mapcheck(t_player *p, int i, int len)
{
    int k;
    int ret;

    k = 0;
    ret = 0;
    while (isWhitespace(p->map.map[i][k]))
        k++;
    while (p->map.map[i][k] && ret != -1)
    {
        if (p->map.map[i][k] == ' ')
            ret = verify_space(p, i, k);
        else if (p->map.map[i][k] == '1')
            ret = 1;
        else
            ret = verify_else(p, i, k);
        k++;
    }
    if (ret == -1)
        return (error(MAP_OPEN_ERROR));
    return (0);
}