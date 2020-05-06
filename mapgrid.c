/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgrid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:17:01 by kmin              #+#    #+#             */
/*   Updated: 2020/05/06 17:55:11 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    oneLine_len(t_player *p, char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == '1' || line[i] == '0' || line[i] == '2' || line[i] == ' ')
            count++;
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
        {
            setPosition(p, line[i]);
            count++;
        }
        i++;
    }
    return (count);
}

char    *mapCopy1(t_player *p, char *line)
{
    int i;
    int j;
    int l_len;
    char *tmp;

    i = 0;
    j = 0;
    l_len = oneLine_len(p, line);
    tmp = (char *)ft_calloc(l_len + 1, sizeof(char));
    while (line[i])
    {
        if (line[i] == '1' || line[i] == '0' || line[i] == '2' || line[i] == 'N' ||
        line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
            tmp[j++] = line[i];
        else if (!isWhitespace(line[i]))
        {
            free(tmp);
            return (NULL);
        }
        i++;
    }
    return (tmp);
}

int mapGrid(t_player *p, char *line)
{
    char **ptr;
    int i;

    i = 0;
    if (!(ptr = (char **)ft_calloc(p->map.height + 2, sizeof(char *))))
        return (error(MAP_ALLOCATION_ERROR));
    while (i < p->map.height)
        ptr[i++] = p->map.map[i];
    if ((ptr[i] = mapCopy1(p, line)) == NULL)
    {
        free(ptr);
        return (error(CHAR_IN_MAP_ERROR));
    }
    if (p->map.map)
    {
        free(p->map.map);
        p->map.map = NULL;
    }
    p->map.map = ptr;
    p->map.height += 1;
    return (0);
}