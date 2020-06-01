/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:21:19 by kmin              #+#    #+#             */
/*   Updated: 2020/05/31 16:11:19 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == 'f' || c == 'r');
}

int	setposition(t_player *p, char c, int i, int r)
{
	p->unit.posx = i + 0.5;
	p->unit.posy = r + 0.5;
	if (c == 'N')
	{
		p->unit.diry = -1;
		p->unit.angle = (3 * M_PI) / 2;
	}
	else if (c == 'S')
	{
		p->unit.diry = 1;
		p->unit.angle = M_PI / 2;
	}
	else if (c == 'E')
	{
		p->unit.dirx = 1;
		p->unit.angle = 2 * M_PI;
	}
	else if (c == 'W')
	{
		p->unit.dirx = -1;
		p->unit.angle = M_PI;
	}
	if (p->unit.pos != 1)
		return (-1);
	return (0);
}

int	skip_space(char *str, int *i)
{
	while (iswhitespace(str[*i]))
		(*i)++;
	return (0);
}

int	iswall(char c)
{
	return (c == ' ' || c == '1');
}

int	iscomp(char c)
{
	int ret;

	if (c == '1' || c == '0' || c == '2' || c == 'W' ||
			c == 'E' || c == 'S' || c == 'N')
		ret = 1;
	else
		ret = 0;
	return (ret);
}
