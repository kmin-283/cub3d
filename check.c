/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:56:16 by kmin              #+#    #+#             */
/*   Updated: 2020/05/19 16:00:23 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int empty_file(t_player *p, int *val)
{
    if (*val == 0)
    {
        if (p->unit.x == 0 && p->unit.y == 0 && p->scr.height == 0 &&
            p->scr.width == 0 && p->tex.no == NULL && p->tex.so == NULL &&
            p->tex.we == NULL && p->tex.ea == NULL && p->tex.sp == NULL &&
            p->tex.c == 0 && p->tex.f == 0 && p->map.height == 0)
            {
                *val = -1;
                return (1);
            }
        else
            return (0);
    }
    else
        return (0);
}

int check_cub(t_player *p)
{
    if (p->tex.no == NULL || p->tex.so == NULL || p->tex.we == NULL ||
    p->tex.ea == NULL || p->tex.sp == NULL || p->tex.c == 0 || p->tex.f == 0)
        return (error(TEXTURE_ERROR));
    return (0);
}

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

int nameCheck(char *name, char *check)
{
    int i;

    i = 0;
    while (name[i])
        i++;
    if (name[i - 4] == check[0] && name[i - 3] == check[1] &&
    name[i - 2] == check[2] && name[i - 1] == check[3])
        return (1);
    else
    {
        error(NAME_INVALID_ERROR);
        return (0);
    }
}

int saveCheck(char *save)
{
    int i;

    i = 0;
    while (save[i])
        i++;
    if (save[i - 6] == '-' && save[i - 5] == '-' &&
    save[i - 4] == 's' && save[i - 3] == 'a' &&
    save[i - 2] == 'v' && save[i - 1] == 'e')
        return (1);
    else
    {
        error(SAVE_INVALID_ERROR);
        return (0);
    }
}