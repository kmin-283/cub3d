/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:56:16 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 17:37:04 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
            if (ptr[k++] != '1')
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