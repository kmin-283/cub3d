/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:56:16 by kmin              #+#    #+#             */
/*   Updated: 2020/05/15 19:22:52 by kmin             ###   ########.fr       */
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

int mapcheck(t_player *p, int i, int len)
{
    char *ptr;
    int k;

    ptr = p->map.map[i];
    k = 0;
    while (isWhitespace(ptr[k]))
        k++;
    if (i == 0 || i == p->map.height - 1)
    {
        while (ptr[k])
        {
            if (ptr[k] == '1' || ptr[k] == ' ')
                k++;
            else
                return (error(MAP_OPEN_ERROR));
        }
    }
    else
    {
        if (p->map.map[i][0] != '1' || p->map.map[i][len - 1] != '1')
            return (error(MAP_OPEN_ERROR));
    }
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