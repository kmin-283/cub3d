/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgrid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:17:01 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 20:09:25 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int setMapWidth(t_player *p)
{
    int **width;
    int i;
    int ret;

    i = 0;
    if (!(width = (int **)ft_calloc(p->map.height, sizeof(int *))))
        return (error(WIDTH_ALLOCATION_ERROR));
    while (i < p->map.height && ret != -1)
    {
        if (!(width[i] = (int *)ft_calloc(2, sizeof(int))))
        {
            free(width);
            return (error(WIDTH_ALLOCATION_ERROR));
        }
        width[i][0] = i;
        width[i][1] = ft_strlen(p->map.map[i]);
        ret = mapcheck(p, i, width[i][1]);
        i++;
    }
    p->map.width = width;
    return (ret);
}

int    oneLine_len(t_player *p, char *line, int r)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
            count++;
        else if (line[i] == '2')
        {
            sprite_cor(p, r, i);
            count++;
        }
        else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
        {
            setPosition(p, line[i]);
            count++;
        }
        i++;
    }
    return (count);
}

char    *mapCopy1(t_player *p, char *line, int row)
{
    int i;
    int j;
    int l_len;
    char *tmp;

    i = 0;
    j = 0;
    l_len = oneLine_len(p, line, row);
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
    if ((ptr[i] = mapCopy1(p, line, i)) == NULL)
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