/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgrid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:17:01 by kmin              #+#    #+#             */
/*   Updated: 2020/05/23 21:46:20 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		setmapwidth(t_player *p)
{
	int *width;
	int i;
	int k;
	int ret;

	i = 0;
	ret = 0;
	if (!(width = (int *)ft_calloc(p->map.height, sizeof(int))))
		return (error(WIDTH_ALLOCATION_ERROR));
	while (i < p->map.height && ret != -1)
	{
		k = 0;
		while (iswhitespace(p->map.map[i][k]))
			k++;
		while (p->map.map[i][k])
		{
			width[i] += 1;
			k++;
		}
		ret = mapcheck(p, i, width[i]);
		i++;
	}
	if (!p->map.width)
		p->map.width = width;
	return (ret);
}

int		oneline_len(t_player *p, char *l, int r, int *err)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (l[i])
	{
		if (l[i] == '1' || l[i] == '0' || l[i] == ' ')
			count++;
		else if (l[i] == '2')
		{
			p->map.spr_num++;
			count++;
		}
		else if (l[i] == 'N' || l[i] == 'S' || l[i] == 'E' || l[i] == 'W')
		{
			p->unit.pos += 1;
			*err = setposition(p, l[i], i, r);
			count++;
		}
		else
			p->map.wrong_char += 1;
		i++;
	}
	return (count);
}

char	*mapcopy1(t_player *p, char *line, int row, int *ret)
{
	int		i;
	int		j;
	int		l_len;
	char	*tmp;

	i = 0;
	j = 0;
	l_len = oneline_len(p, line, row, ret);
	if (*ret == -1)
		return (NULL);
	if ((tmp = (char *)ft_calloc(l_len + 1, sizeof(char))) == NULL)
		return (NULL);
	while (line[i])
	{
		tmp[j++] = line[i];
		i++;
	}
	return (tmp);
}

int		mapgrid(t_player *p, char *line)
{
	char	**ptr;
	int		i;
	int		ret;

	i = 0;
	if (!(ptr = (char **)ft_calloc(p->map.height + 2, sizeof(char *))))
		return (error(MAP_ALLOCATION_ERROR));
	while (i < p->map.height)
	{
		ptr[i] = p->map.map[i];
		i++;
	}
	if ((ptr[i] = mapcopy1(p, line, i, &ret)) == NULL)
	{
		free(ptr);
		return (error(CHAR_IN_MAP_ERROR));
	}
	if (p->map.map)
		free(p->map.map);
	if (ptr)
		p->map.map = ptr;
	p->map.height += 1;
	return (0);
}
